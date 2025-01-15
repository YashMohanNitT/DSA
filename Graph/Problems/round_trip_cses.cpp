/*
	Byteland has n cities and m roads between them. 
	Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. 
	Every intermediate city on the route has to be distinct.
	
	Input
	The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,...,n.
	Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
	Every road is between two different cities, and there is at most one road between any two cities.
	
	Output
	First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
	If there are no solutions, print "IMPOSSIBLE".
	
	Constraints
 
	1 <= n <= 10^5
	1 <= m <= 2*10^5
	1 <= a,b <= n
 
	Example
	Input:
	5 6
	1 3
	1 2
	5 3
	1 5
	2 4
	4 5
 
	Output:
	4
	3 5 1 3
*/
#include <bits/stdc++.h>
 
#define endl            "\n"
#define all(x)           x.begin(), x.end()
#define yash            ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define w()             int t; cin>>t; while(t--)
#define rep(i,a,b)      for(int i=a;i<b;++i)
#define vpii            vector<pair<int, int>>
#define vi              vector<int>
#define vvi             vector<vector<int>>
#define read(v,n)       rep(i,0,n) cin>>v[i];
#define int             long long
#define ull             unsigned long long
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;
#define pq              priority_queue
#define mod             1000000007
 
using namespace std;
vector<string> split(const string& s, char c) {
	vector<string> v; stringstream ss(s); string x;
	while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
	stringstream s; s << "[";
	for (int i = 0; i < n - 1; i++) s << arr[i] << ",";
	s << arr[n - 1] << "]";
	return s.str();
}
template<typename t>
void evars(vector<vector<t>> a){
    for(auto i:a){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
#define EVARS(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}
 
inline void __evars_begin(int line) { cout << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cout << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cout << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cout << val; }
inline void __evars(vector<string>::iterator it) { cout << endl; }
 
template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
	cout << it->substr((*it)[0] == ' ', it->length()) << "=";
	__evars_out_var(a);
	cout << "; ";
	__evars(++it, args...);
}
bool dfs(int currCity, int prev, vector<int> &path, 
			vector<bool> &visited, vector<vector<int>> &adj) {
	visited[currCity] = true;
	for (int nextCity : adj[currCity]) {
		path.push_back(nextCity);
		if (!visited[nextCity]) {
			if(dfs(nextCity, currCity, path, visited, adj)) { // found a cycle
				return true;
			}
		}
		else if (nextCity != prev) {
			return true;
		}
		path.pop_back();
	}
	return false;
}
 
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> visited(n + 1, false);
	vector<int> path;
	for (int city = 1; city <= n; ++city) {
		path.push_back(city);
		if(!visited[city] && dfs(city, -1, path, visited, adj)) {
			int repeatedVertex = path[path.size() - 1], cycleStart = INT_MAX;
			for (int i = 0; i < path.size() - 1; ++i) {
				if (repeatedVertex == path[i]) {
					cycleStart = i;
					break;
				}
			}
			cout << path.size() - cycleStart << endl;
			for (int i = cycleStart; i < path.size(); ++i) {
				cout << path[i] << " ";
			}
			cout << endl;
			return;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
 
int32_t main()
{
    clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    yash;
    //w()
    solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}