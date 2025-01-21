/*
	https://codeforces.com/contest/2060/problem/C
*/
#include<bits/stdc++.h>

using namespace std;

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
#define lld             long double
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// Debug utility functions
template <typename T> void _print(const T &x) { cerr << x; }
template <typename T, typename U> void _print(const pair<T, U> &p) { cerr << "{" << p.first << "," << p.second << "}"; }
template <typename T> void _print(const vector<T> &v) { cerr << "["; for (int i = 0; i < v.size(); i++) cerr << (i ? ", " : "") << v[i]; cerr << "]"; }
template <typename T> void _print(const set<T> &s) { cerr << "{"; for (auto it = s.begin(); it != s.end(); it++) cerr << (it == s.begin() ? "" : ", ") << *it; cerr << "}"; }
template <typename T> void _print(const multiset<T> &ms) { _print(set<T>(ms.begin(), ms.end())); }
template <typename K, typename V> void _print(const map<K, V> &m) { cerr << "{"; for (auto it = m.begin(); it != m.end(); it++) cerr << (it == m.begin() ? "" : ", ") << *it; cerr << "}"; }

vector<string> _split(string s) {
    vector<string> v; stringstream ss(s); string tmp;
    while (getline(ss, tmp, ',')) v.push_back(tmp);
    return v;
}

template <class T, class... Args>
void _debug_print(const vector<string> &vars, int idx, const T &val, const Args &...args) {
    cerr << vars[idx] << " = "; _print(val);
    if (sizeof...(args)) cerr << ", ";
    if constexpr (sizeof...(args) > 0) _debug_print(vars, idx + 1, args...);
}

#ifndef ONLINE_JUDGE
#define debug(...) do { \
    cerr << __LINE__ << " : "; \
    vector<string> vars = _split(#__VA_ARGS__); \
    _debug_print(vars, 0, __VA_ARGS__); \
    cerr << "\n"; \
} while (0)
#else
#define debug(...)
#endif
void setIO(string fileName, bool useLocal){ // give fileName for USACO site
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!useLocal) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    } else {
        #ifndef ONLINE_JUDGE
            freopen("error.txt", "w", stderr);
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
    }
}


int32_t main() {
    setIO("", true);
    w() {
    	int n, k;
    	cin >> n >> k;
    	vi a(n);
    	read(a, n);
    	map<int, int> freq;
    	rep(i, 0 , n) {
    		freq[a[i]]++;
    	}
    	
    	int ans = 0;
    	rep(i, 0 , n) {
    		int A = a[i], b = k - a[i];
    		if (A != b){
				int currMin = min(freq[A], freq[b]);
	    		freq[A] -= currMin;
	    		freq[b] -= currMin;
    			ans += currMin;
	    	} else {
				int currMin = min(freq[A], freq[b]);
	    		freq[A] = 0;
	    		ans += currMin/2;
	    	}
    	}
    	cout << ans << endl;
    }



    
    return 0;
}