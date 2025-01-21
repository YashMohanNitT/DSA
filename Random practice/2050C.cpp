/*
    Problem link/desc
*/
#include<bits/stdc++.h>

using namespace std;

#define endl            "\n"
#define all(x)          x.begin(), x.end()
#define yash            ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define w()             int t; cin>>t; while(t--)
#define rep(i,a,b)      for(int i=a;i<b;++i)
#define vpii            vector<pair<int, int>>
#define vi              vector<int>
#define vvi             vector<vector<int>>
#define read(v)         for(auto &i : v) cin>>i;
#define int             long long
#define ull             unsigned long long
#define lld             long double
#define out(v)          for(auto &i : v) {cout << i << " ";} cout << endl;;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// Debug print helpers
template <typename T> void _print(const T &x) { cerr << x; }
template <typename T, typename U> void _print(const pair<T, U> &p) {
    cerr << "{" << p.first << "," << p.second << "}";
}
template <typename T> void _print(const vector<T> &v) {
    cerr << "[";
    for (size_t i = 0; i < v.size(); i++){
        if (i) cerr << ", ";
        _print(v[i]);
    }
    cerr << "]";
}
template <typename T> void _print(const set<T> &s) {
    cerr << "{";
    for (typename set<T>::const_iterator it = s.begin(); it != s.end(); ++it) {
        if (it != s.begin()) cerr << ", ";
        _print(*it);
    }
    cerr << "}";
}
template <typename K, typename V> void _print(const map<K,V> &m) {
    cerr << "{";
    for (typename map<K,V>::const_iterator it = m.begin(); it != m.end(); ++it) {
        if (it != m.begin()) cerr << ", ";
        cerr << "{";
        _print(it->first);
        cerr << ",";
        _print(it->second);
        cerr << "}";
    }
    cerr << "}";
}

vector<string> _split(const string &s) {
    vector<string> v;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, ',')) v.push_back(tmp);
    return v;
}

// Base case for _debug_print
template <class T>
void _debug_print(const vector<string> &vars, int idx, const T &val) {
    cerr << vars[idx] << " = ";
    _print(val);
    cerr << "\n";
}

// Variadic case for _debug_print
template <class T, class... Args>
void _debug_print(const vector<string> &vars, int idx, const T &val, const Args &...args) {
    cerr << vars[idx] << " = ";
    _print(val);
    if (sizeof...(args)) cerr << ", ";
    _debug_print(vars, idx + 1, args...);
}

#ifndef ONLINE_JUDGE
#define debug(...) do {                          \
    cerr << __LINE__ << " : ";                   \
    vector<string> vars = _split(#__VA_ARGS__);  \
    _debug_print(vars, 0, __VA_ARGS__);          \
    cerr << "\n";                                \
} while(0)
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
        string s;
        cin >> s;
        int sum = 0;
        int twos = 0, threes = 0;
        for (char &c : s) {
            sum += c - '0';
            twos += (c == '2');
            threes += (c == '3');
        }
        debug(s, twos, threes, sum);
        bool ok = true;
        for (int i = 0; i <= min(8LL, twos); ++i) {
            for (int j = 0; j <= min(8LL, threes); ++j) {
                if ((sum + 2*i + 6*j)%9 == 0) {
                    cout << "YES\n";
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        if (ok) {
            cout << "NO\n";
        }
    }
    return 0;
}