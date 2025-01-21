/*
	https://usaco.org/index.php?page=viewproblem2&cpid=668
*/
#include <bits/stdc++.h>
 
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
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;
#define pq              priority_queue
#define mod             1000000007
 
using namespace std;
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
	cout << "----------------------" << endl;
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

void setIO(string name, bool useLocal){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!useLocal) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    } else {
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
    }
}

void solve() {
	setIO("moocast", true);
	int n;
	cin >> n;
	vector<vector<int>> cowPos, d(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		int x, y, power;
		cin >> x >> y >> power;
		// vector<int> info = ;
		cowPos.push_back({x, y, power});
	}
	for (int i = 0; i < n; ++i) {
		int currCowX = cowPos[i][0], currCowY = cowPos[i][1], currPower = cowPos[i][2];
		for (int j = i + 1; j < n; ++j) {
			int nextCowX = cowPos[j][0], nextCowY = cowPos[j][1], nextPower = cowPos[j][2];
			int xDiff = currCowX - nextCowX, yDiff = currCowY - nextCowY;
			if (xDiff*xDiff + yDiff*yDiff <= currPower*currPower) {
				// currCow -> nextCow;
				d[i][j] = 1;
			}
			if (xDiff*xDiff + yDiff*yDiff <= nextPower*nextPower) {
				// nextCow -> currCow;
				d[j][i] = 1;
			}
		}
	}
	int maxLen = 0;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if(i != j){
					d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
				}
				else {
					d[i][j] = true;
				}
			}
		}
	}
	// evars(d);
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			d[i][j] += d[i][j - 1];
		}
		maxLen = max(maxLen, d[i][n - 1]);
	}
	// evars(d);
	cout << maxLen;
}
 
int32_t main()
{
    solve();
    return 0;
}