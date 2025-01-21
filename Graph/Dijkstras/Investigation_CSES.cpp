/*
	You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to the following questions:

	what is the minimum price of such a route?
	how many minimum-price routes are there? (modulo 10^9+7)
	what is the minimum number of flights in a minimum-price route?
	what is the maximum number of flights in a minimum-price route?

	Input
	The first input line contains two integers n and m: the number of cities and the number of flights. The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Lehmälä.
	After this, there are m lines describing the flights. Each line has three integers a, b, and c: there is a flight from city a to city b with price c. All flights are one-way flights.
	You may assume that there is a route from Syrjälä to Lehmälä.
	
	Output
	Print four integers according to the problem statement.
	Constraints

	1 <= n <= 10^5
	1 <= m <= 2*10^5
	1 <= a,b <= n
	1 <= c <= 10^9

	Example
	Input:
	4 5
	1 4 5
	1 2 4
	2 4 5
	1 3 2
	3 4 3

	Output:
	5 2 1 2
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
	vector<int> dist(n + 1, LLONG_MAX), numRoutes(n + 1, 0), minNumOfFlights(n + 1, 0), maxNumOfFlights(n + 1, 0);
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, 1));
	dist[1] = 0;
	numRoutes[1] = 1;
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
			// Found a shorter path to nextCity
			if (nextCityDistance < dist[nextCity]) {
				dist[nextCity] = nextCityDistance;
				numRoutes[nextCity] = numRoutes[currCity];
				minNumOfFlights[nextCity] = minNumOfFlights[currCity] + 1;
				maxNumOfFlights[nextCity] = maxNumOfFlights[currCity] + 1;
				pq.push(pii(nextCityDistance, nextCity));
			} 
			// Found an alternative path with the same shortest distance
			else if (nextCityDistance == dist[nextCity]) {
				numRoutes[nextCity] = (numRoutes[currCity] + numRoutes[nextCity])%mod;
				minNumOfFlights[nextCity] = min(minNumOfFlights[nextCity], minNumOfFlights[currCity] + 1);
				maxNumOfFlights[nextCity] = max(maxNumOfFlights[nextCity], maxNumOfFlights[currCity] + 1);
			}
		}
	}
	cout << dist[n] << " " << numRoutes[n] << " " << minNumOfFlights[n] << " " << maxNumOfFlights[n] << endl;
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