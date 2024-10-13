/*
	Consider a money system consisting of n coins. 
	Each coin has a positive integer value. 
	Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
	
	For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:

	2+2+5
	3+3+3
	2+2+2+3
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
vector<int> dp;
int ways(int n) {
	// EVARS(n)
	if (n < 10) return 1;
	if (n < 0) return INT_MAX;

	if(dp[n] != -1) {
		return dp[n];
	}
	int temp = n;
	vector<int> digits;
	while(temp) {
		if (temp%10) {
			digits.push_back(temp%10);
		}
		temp /= 10;
	}
	// EVARS(digits)
	int ans = INT_MAX;
	for (int curr : digits) {
		ans = min(ans, ways(n - curr) + 1);
	}
	return dp[n] = ans;
}
void solve() {
	int n;
	cin >> n;
	dp.assign(n + 1, INT_MAX);
	for(int i = 1; i < 10; ++i) {
		dp[i] = 1;
	}
	for (int i = 10; i <= n; ++i) {
		int temp = i;
		vector<int> digits;
		while(temp) {
			if (temp%10) {
				digits.push_back(temp%10);
			}
			temp /= 10;
		}
		// EVARS(digits)
		for (int curr : digits) {
			dp[i] = min(dp[i], dp[i - curr] + 1);
		}
	}
	cout << dp[n];
	/*dp.assign(n + 1, -1);
	cout << ways(n);*/
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