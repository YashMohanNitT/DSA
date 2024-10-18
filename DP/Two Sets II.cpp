/*
    Your task is to count the number of ways numbers 1,2,...,n can be divided into two sets of equal sum.
    For example, if n=7, there are four solutions:

    {1,3,4,6} and {2,5,7}
    {1,2,5,6} and {3,4,7}
    {1,2,4,7} and {3,5,6}
    {1,6,7} and {2,3,4,5}

    Input
        The only input line contains an integer n.
    
    Output
        Print the answer modulo 10^9+7.
    
    Constraints

        1 <= n <= 500

    Example
        Input:
        7

        Output:
        4
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
const int MAX_NUM = 500;
const int MAX_SUM = MAX_NUM*(MAX_NUM + 1)/2;
 
int n, goalSum;
int mem[MAX_NUM + 1][MAX_SUM + 1];
int dp(int idx, int sum) {
    if (idx > n) {
        return sum == goalSum;
    }
    if(mem[idx][sum] != -1) {
        return mem[idx][sum];
    }
    int ans = 0;
    // Option 1: Include the current number in the subset
    ans = (ans + dp(idx + 1, sum + idx)) % mod;
    // Option 2: Exclude the current number from the subset
    ans = (ans + dp(idx + 1, sum)) % mod;
    return mem[idx][sum] = ans;
}
 
 
void solve() {
    cin >> n;
    goalSum = n*(n+1)/2;
    if(goalSum%2) {
        cout << 0 << endl;
        return;
    }
    goalSum /= 2;
    memset(mem, -1, sizeof(mem));
    int inv2 = (mod + 1) / 2;
    int ans = dp(1, 0);
    cout << (ans*inv2)%mod;
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