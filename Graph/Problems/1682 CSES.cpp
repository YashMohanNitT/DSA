/*
    There are n cities and m flight connections. Your task is to check if you can travel from any city to any other city using the available flights.
    Input
    The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,...,n.
    After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. All flights are one-way flights.
    Output
    Print "YES" if all routes are possible, and "NO" otherwise. In the latter case also print two cities a and b such that you cannot travel from city a to city b. If there are several possible solutions, you can print any of them.
    Constraints

    1 <= n <= 10^5
    1 <= m <= 2*10^5
    1 <= a,b <= n

    Example
    Input:
    4 5
    1 2
    2 3
    3 1
    1 4
    3 4

    Output:
    NO
    4 2
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
 
void dfs(int curr, vector<bool> &visited, vector<vector<int>> &adj) {
    visited[curr] = true;
    for (int next : adj[curr]) {
        if (!visited[next]) {
            dfs(next, visited, adj);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), rAdj(n + 1);
    int fromCity, toCity;
    for(int i = 0; i < m; ++i) {
        cin >> fromCity >> toCity;
        adj[fromCity].push_back(toCity);
        rAdj[toCity].push_back(fromCity);
    }
    vector<bool> visited(n + 1, false);
    dfs(1, visited, adj);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return;
        }
    }
    visited = vector<bool>(n + 1, false);
    dfs(1, visited, rAdj);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return;
        }
    }
    cout << "YES" << endl;
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