/*
	https://cses.fi/problemset/task/1195
	
	Your task is to find a minimum-price flight route from Syrjälä to Metsälä. 
	You have one discount coupon, using which you can halve the price of any single flight 
	during the route. However, you can only use the coupon once.
	When you use the discount coupon for a flight whose price is x, its price becomes
	x/2(it is rounded down to an integer).
	
	Constraints

	2 <= n <= 10^5
	1 <= m <= 2*10^5
	1 <= a,b <= n
	1 <= c <= 10^9

	Example
	Input:
	3 4
	1 2 3
	2 3 1
	1 3 7
	2 1 5

	Output:
	2
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
 
/**
 * given a start point, and an adjacency list with costs,
 * this function gives an array with the minimum distances
 * from all the other nodes to the start node
 * (the value is INT64_MAX if unreachable)
 */
vector<long long> min_costs(int from, vector<vector<pair<int, int>>> &neighbors) {
	vector<long long> min_costs(neighbors.size(), INT64_MAX);
	min_costs[from] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	q.push({0, from});
	while (!q.empty()) {
		pair<long long, int> curr_state = q.top();
		q.pop();
		int curr = curr_state.second;
		if (curr_state.first != min_costs[curr]) { 
			continue; 
		}

		for (auto [n, nc] : neighbors[curr]) {
			long long new_cost = min_costs[curr] + nc;
			if (new_cost < min_costs[n]) {
				min_costs[n] = new_cost;
				q.push({new_cost, n});
			}
		}
	}
	return min_costs;
}

void solve() {
	int city_num, flight_num;
	cin >> city_num >> flight_num;
	vector<vector<pair<int, int>>> neighbors(city_num);
	vector<vector<pair<int, int>>> reverse_neighbors(city_num);
	for (int f = 0; f < flight_num; f++) {
		int from;
		int to;
		int cost;
		std::cin >> from >> to >> cost;
		neighbors[--from].push_back({--to, cost});
		reverse_neighbors[to].push_back({from, cost});
	}

	vector<long long> start_costs = min_costs(0, neighbors);
	vector<long long> end_costs = min_costs(city_num - 1, reverse_neighbors);
	long long total_min = INT64_MAX;
	for (int c = 0; c < city_num; c++) {
		for (auto [n, nc] : neighbors[c]) {
			if (start_costs[c] == INT64_MAX || end_costs[n] == INT64_MAX) {
				continue;
			}
			total_min =
			    std::min(total_min, start_costs[c] + (nc / 2) + end_costs[n]);
		}
	}
	cout << total_min << endl;
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