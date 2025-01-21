/*
    Problem link/desc
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
#define mod             998244353
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
//---------------------------------------------------------------------------------------
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

//---------------------------------------------------------------------------------------

const int maxK = 100005;
const int maxR = 20;
int dp[maxK][maxR];
int fact[maxR], invFact[maxR];

int modexp(long long base, long long exp){
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) 
            res = (res*base) % mod;
        base = (base*base) % mod;
        exp >>= 1;
    }
    return res;
};

void precomputeFacts() {
    fact[0] = 1;
    for (int r = 1; r < maxR; r++) 
        fact[r] = (fact[r-1]*r) % mod;

    for (int r=0; r<maxR; r++) {
        invFact[r] = modexp(fact[r], mod-2);
    }
}

void precompute() {
    memset(dp, 0, sizeof(dp));

    precomputeFacts();

    vvi divisors(maxK);
    for (int k = 2; k < maxK; ++k) {
        for (int d = k; d < maxK; d += k) {
            divisors[d].push_back(k);
        }
    }
    
    for (int r = 2; r < maxK; ++r) {
        dp[r][1] = 1;
    }

    for (int x = 2; x < maxK; ++x) {
        for (int r = 2; r < maxR; ++r) {
            for (int f : divisors[x]) {
                dp[x][r] = (dp[x][r]%mod + dp[x/f][r - 1]%mod)%mod;
            }
        }
    }
} 

int nCr(int n, int r) {
    if (r > n) 
        return 0;
    if (r == 0) 
        return 1;
    int ans = 1;
    for (int n_i = n; n_i > n - r; --n_i) {
        ans = (ans * (n_i % mod)) % mod;
    }
    ans = (ans * invFact[r]) % mod;
    return ans;
}

int32_t main() {
    setIO("", true);
    precompute();
    w() {
        int k, n;
        cin >> k >> n;
        // debug(k, n);
        vi combsOfSumNcR(maxR, 0);
        for (int r = 1; r < maxR; ++r) {
            combsOfSumNcR[r] = nCr(n + 1, r + 1);
        }
        int ans = n;
        cout << ans << " ";
        for (int x = 2; x <= k; ++x) {
            ans = 0;
            for (int r = 1; r < maxR; ++r) {
                if (dp[x][r] != 0) {
                    ans = (ans + (dp[x][r] * combsOfSumNcR[r])%mod)%mod;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }    
    return 0;
}