 /*
    You have n coins with certain values. 
    Your task is to find all money sums you can create using these coins.
    
    Input
        The first input line has an integer n: the number of coins.
        The next line has n integers x1,x2,...,xn: the values of the coins.
    
    Output
        First print an integer k: the number of distinct money sums. 
        After this, print all possible sums in increasing order.
    
    Constraints

        1 <= n <= 100
        1 <= xi <= 1000

    Example
        Input:
            4
            4 2 5 2

        Output:
            9
            2 4 5 6 7 8 9 11 13
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

bool possible(int sum, int idx, vi& coins, vvi &dp) {
    if(sum == 0) {
        return true;
    }
    if (sum < 0 || idx > coins.size()) {
        return false;
    }
    if (dp[sum][idx] != -1) {
        return dp[sum][idx];
    }
    return dp[sum][idx] = possible(sum - coins[idx], idx + 1, coins, dp) || possible(sum, idx + 1, coins, dp);
}

void solve() {
    /*int n;
    cin >> n;
    vi coins(n), ans;
    read(coins, n);
    int totalSum = accumulate(coins.begin(), coins.end(), 0LL);
    vi dp(totalSum + 1);
    for (int i = 1; i < totalSum; ++i) {
        if (possible(i, 0, coins, dp)) {
            ans.push_back(i);
        }
    }
    ans.push_back(totalSum);
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << " ";
    }*/
/*    int n;
    cin >> n;
    vi coins(n);
    read(coins, n);

    // Calculate the total sum of the coins
    int totalSum = accumulate(coins.begin(), coins.end(), 0LL);

    // Create a DP table to track possible sums
    vector<vector<bool>> dp(totalSum + 1, vector<bool>(n + 1, false));

    // Base case: it's always possible to form a sum of 0 using no coins
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= totalSum; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Exclude the current coin (same as dp[i][j-1])
            dp[i][j] = dp[i][j-1];

            // Include the current coin if the sum is possible (check if dp[i - coins[j-1]][j-1] is true)
            if (i - coins[j-1] >= 0) {
                dp[i][j] = dp[i][j] || dp[i - coins[j-1]][j-1];
            }
        }
    }

    // Collect all possible sums
    vi ans;
    for (int i = 1; i <= totalSum; ++i) {
        if (dp[i][n]) {
            ans.push_back(i);
        }
    }

    // Output the result
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << " ";
    }*/
        int n;
    cin >> n;
    vi coins(n);
    read(coins, n);

    // Calculate the total sum of the coins
    int totalSum = accumulate(coins.begin(), coins.end(), 0LL);

    // Create a DP array to track possible sums
    // dp[i] will be true if sum `i` can be formed with some subset of coins
    vector<bool> dp(totalSum + 1, false);
    dp[0] = true; // Base case: sum of 0 is always possible

    // Update the DP array for each coin
    for (int coin : coins) {
        // Iterate backwards to avoid overwriting previous states
        for (int i = totalSum; i >= coin; --i) {
            dp[i] = dp[i] || dp[i - coin];
        }
    }

    // Collect all possible sums
    vi ans;
    for (int i = 1; i <= totalSum; ++i) {
        if (dp[i]) {
            ans.push_back(i);
        }
    }

    // Output the result
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << " ";
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