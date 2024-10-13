/*
    Consider a money system consisting of n coins. Each coin has a positive integer value. 
    Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
    For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
 
    2+2+5
    2+5+2
    5+2+2
    3+3+3
    2+2+2+3
    2+2+3+2
    2+3+2+2
    3+2+2+2
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
template<typename T> inline void __evars_out_var(vector<vector<T>> vals) { 
    // cout << endl;
    for(vector<T> &val : vals) {
        cout << arrStr(val, val.size());
        cout << endl;
    }
}
template<typename T> inline void __evars_out_var(T* val) { cout << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cout << val; }
inline void __evars(vector<string>::iterator it) { cout << endl; }
template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cout << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cout << "; \n";
    __evars(++it, args...);
}
 
int countWays(int sum, vector<int> &coins, vector<int> &dp) {
    if (sum == 0) return 1;      // Base case: one way to make sum 0
    if (dp[sum] != -1) return dp[sum]; // Return memoized result
    int ways = 0;
    for (int coin : coins) {
        if (sum >= coin) {
            ways = (ways + countWays(sum - coin, coins, dp)) % mod;
        }
    }
    return dp[sum] = ways;
}
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
 
/*    vector<int> dp(x + 1, 0);
    dp[0] = 1;  // Base case
 
    for (int sum = 1; sum <= x; ++sum) {
        for (int coin : coins) {
            if (sum - coin >= 0) {
                dp[sum] = (dp[sum] + dp[sum - coin])%mod;
            }
        }
    }
    cout << dp[x] << endl;*/
    
    vector<int> dp(x + 1, -1);  // Initialize memoization array with -1
    int result = countWays(x, coins, dp);
    if (result == INT_MAX) {
        cout << -1 << endl;  // Not possible to make sum x
    } else {
        cout << result << endl;  // Minimal number of coins needed
    }
    
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