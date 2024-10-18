/*

You are in a book shop which sells n different books. 
You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. 
What is the maximum number of pages you can buy? You can buy each book at most once.

Input
	The first input line contains two integers n and x: the number of books and the maximum total price.
	The next line contains n integers price1,....,pricen: the price of each book.
	The last line contains n integers page1,....,pagen: the number of pages of each book.
 
Output
	Print one integer: the maximum number of pages.

Example
	Input:
		4 10
		4 8 5 3
		5 12 8 1

	Output:
		13

	Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.
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
int f(int idx, int x, vector<int> &h, vector<int> &s, vector<vector<int>> &dp){
	if(idx == h.size() || x == 0){
		return 0;
	}
	if(dp[idx][x] != -1){
		return dp[idx][x];
	}
	int ans = f(idx + 1, x, h, s, dp);
	if(x >= h[idx]){
		ans = max(ans, s[idx] + f(idx + 1, x - h[idx], h, s, dp));
	}
	return dp[idx][x] = ans;
}
void solve() {
	int n, x;
    cin >> n >> x;
    vector<int> pages(n), prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
 	for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }
    vector<int> dp(x + 1, 0);

	for (int idx = 0; idx < n; ++idx) {
	    for (int cost = x; cost >= prices[idx]; --cost) {
	        dp[cost] = max(dp[cost], pages[idx] + dp[cost - prices[idx]]);
	    }
	}
	cout << dp[x] << endl;
    /*vvi dp(n + 1, vi(x + 1, -1));
    cout << f(0, x, prices, pages, dp);*/
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