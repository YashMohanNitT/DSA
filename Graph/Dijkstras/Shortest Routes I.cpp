/*
	https://cses.fi/problemset/task/1671/
	
	There are n cities and m flight connections between them. Your task is to determine the length of the shortest route from Syrjälä to every city.
	Input
	The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,\dots,n, and city 1 is Syrjälä.
	After that, there are m lines describing the flight connections. Each line has three integers a, b and c: a flight begins at city a, ends at city b, and its length is c. Each flight is a one-way flight.
	You can assume that it is possible to travel from Syrjälä to all other cities.
	Output
	Print n integers: the shortest route lengths from Syrjälä to cities 1,2,...,n
	
	Constraints

		1 <= n <= 10^5
		1 <= m <= 2*10^5
		1 <= a,b <= n
		1 <= c <= 10^9

	Example
	Input:

	3 4
	1 2 6
	1 3 2
	3 2 3
	1 3 4
	Output:

	0 5 2
*/

#include <bits/stdc++.h>
 
#define endl            "\n"
#define all(x)            x.begin(), x.end()
#define yash            ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define w()             int t; cin>>t; while(t--)
#define rep(i,a,b)      for(int i=a;i<b;++i)
#define vi                 vector<int>
#define vvi                 vector<vector<int>>
#define read(v,n)        rep(i,0,n) cin>>v[i];
#define int               long long
#define ull               unsigned long long
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;
#define pq                priority_queue
#define mod               1000000007
 
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

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
using pii = pair<int,int>;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<int> dist(n + 1, LLONG_MAX);
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, 1));
	dist[1] = 0;
	while(!pq.empty()) {
		pii top = pq.top(); pq.pop();
		int currDistance = top.first, currCity = top.second;
		/*
			if (currDistance != dist[currCity]) or if(dist[currCityId] < length)  ensures that the curr city being processed has the lowest distance possible.
			- Once the node is processed it won't be processed again.
			- since length is already greater than the current distance of the node to be processed, no extra node added to the current path can reduce its length. 			
		*/
		if (dist[currCity] < currDistance) {
			continue;
		}
		for (auto &[nextCity, distanceBetweenThem] : adj[currCity]) {
			int nextCityDistance = dist[currCity] + distanceBetweenThem;
			if (nextCityDistance < dist[nextCity]) {
				dist[nextCity] = nextCityDistance;
				pq.push(pii(nextCityDistance, nextCity));
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << dist[i] << " ";
	}
	cout << endl;
}
 
int32_t main()
{
    clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    yash;
    // w()
    solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}