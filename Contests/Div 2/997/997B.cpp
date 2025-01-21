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
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

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

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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

int32_t main() {
    setIO("", true);
    // w() {
    // 	int n;
    // 	cin >> n;
    // 	string g[n];
    // 	// cout << n << endl;
    // 	for (auto &s : g) {
    // 		cin >> s;
    // 	}
    // 	vector<int> vals;
    // 	vals.push_back(1);
    // 	for (int i = 1; i < n; ++i) {
    // 		// check if we need to go left or right
    // 		int idx = find(vals.begin(), vals.end(), 1) - vals.begin();
    // 		// debug(idx);
    // 		if (g[0][i] == '1') {
    // 			// always insert data right of wherever 1 is
    // 			// find where 1 is
    // 			int idx1 = idx;
    // 			while(idx + 1 < vals.size() && g[i + 1][vals[idx + 1]] == '1') {
    // 				idx++;
    // 				// debug(idx);
    // 				// debug(g[i + 1][vals[idx + 1]]);
    // 			}
    // 			EVARS(vals, idx)
    // 			// if (idx == idx1) {
    // 			// 	idx++;
    // 			// }
    // 			vals.insert(vals.begin() + idx + 1, i + 1);
    // 			EVARS(vals, idx)
    // 		} else {
    // 			while(idx - 1 >= 0 && g[i + 1][vals[idx - 1]] == '1') {
    // 				idx--;
    // 				// debug(idx);
    // 				// debug(g[i + 1][vals[idx - 1]]);
    // 			}
    // 			EVARS(vals, idx)
    // 			vals.insert(vals.begin() + idx, i + 1);
    // 			EVARS(vals, idx);
    // 		}
    // 	}
    // 	out(vals, vals.size());
    // }
    w() {
        int n;
        cin >> n;

        vector<string> g(n);
        for(int i = 0; i < n; i++){
            cin >> g[i];
        }
        vector<int> vals;
        vals.push_back(1);

        for(int i = 1; i < n; i++){ 
         
            auto it = find(vals.begin(), vals.end(), 1);
            int idx = (int)(it - vals.begin());

            
            if(g[0][i] == '1'){
               
                while(idx + 1 < (int)vals.size() 
                      && g[i][vals[idx + 1] - 1] == '1'){

                    idx++;
                }
                
                vals.insert(vals.begin() + idx + 1, i + 1);

            } else {
              
                while(idx - 1 >= 0 
                      && g[i][vals[idx - 1] - 1] == '0'){
                    idx--;
                }
                
                vals.insert(vals.begin() + idx, i + 1);
            }
        }
        for(int i = 0; i < n; i++){
            cout << vals[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}