/*
	Consider a money system consisting of n coins. Each coin has a positive integer value. 
	Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
	
	For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
	
	Input
		The first input line has two integers n and x: the number of coins and the desired sum of money.
		The second line has n distinct integers c1,c2,...,cn: the value of each coin.
	
	Output
		Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
	
	Constraints

		1 <= n <= 100
		1 <= x <= 10^6
		1 <= ci <= 10^6

	Example
		Input:
			3 11
			1 5 7

		Output:
			3
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

int minCoins(int x, vector<int>& coins, vector<int>& dp) {
    if (x == 0) return 0;           // Base case: 0 coins needed to make sum 0
    if (x < 0) return INT_MAX;      // Cannot make negative sum

    if (dp[x] != -1) return dp[x];  // Return already computed result

    int min_count = INT_MAX;
    for (int coin : coins) {
        int res = minCoins(x - coin, coins, dp);
        if (res != INT_MAX) {
            min_count = min(min_count, res + 1);
        }
    }
    return dp[x] = min_count;
}

void solve() {
	int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;  // Base case

    for (int sum = 1; sum <= x; ++sum) {
        for (int coin : coins) {
            if (sum - coin >= 0) {
                dp[sum] = (dp[sum] + dp[sum - coin])%mod;
            }
        }
    }
    cout << dp[x] << endl;
    /*
    vector<int> dp(x + 1, -1);  // Initialize memoization array with -1
    int result = minCoins(x, coins, dp);
    if (result == INT_MAX) {
        cout << -1 << endl;  // Not possible to make sum x
    } else {
        cout << result << endl;  // Minimal number of coins needed
    }
    */
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