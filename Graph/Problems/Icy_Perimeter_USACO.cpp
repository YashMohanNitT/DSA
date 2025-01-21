/*
	https://usaco.org/index.php?page=viewproblem2&cpid=895
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

int dx[4] = {0 , 0, 1, -1};
int dy[4] = {1 , -1, 0, 0};

int n;
vector<vector<char>> iceCream;
vector<vector<bool>> visited;
int maxPerimeter, maxArea, perimeter, area;

int findPerimeter(int r, int c) {
	int perimeter = 4;
	for (int k = 0; k < 4; ++k) {
		int rr = r + dx[k], cc = c + dy[k];
		if (rr < n && cc < n && rr >= 0 && cc >= 0) {
			perimeter -= (iceCream[rr][cc] == '#');
		}
	}
	return perimeter;
}

void dfs(int r, int c) {
	// debug(r, c);
	if(r >= n || c >= n || r < 0 || c < 0 || visited[r][c] || iceCream[r][c] == '.') {
		return;
	}
	visited[r][c] = true;
	perimeter += findPerimeter(r, c);
	area++;
	dfs(r + 1, c);
	dfs(r, c + 1);
	dfs(r - 1, c);
	dfs(r, c - 1);
}

int32_t main() {
    setIO("perimeter", false);
    cin >> n;
    iceCream = vector<vector<char>>(n , vector<char>(n));
    visited = vector<vector<bool>>(n , vector<bool>(n, false)); 

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		cin >> iceCream[i][j];
    	}
    }
    // debug(iceCream);
    maxPerimeter = maxArea = perimeter = area = 0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		if (iceCream[i][j] == '#' && !visited[i][j]) {
    			perimeter = area = 0;
    			dfs(i, j);
    			if (area >= maxArea) {
    				// debug(area, maxArea, perimeter, maxPerimeter);
    				maxPerimeter = (area == maxArea) ? min(maxPerimeter, perimeter) : perimeter;
    				maxArea = area;
    				// debug(area, maxArea, perimeter, maxPerimeter);
 
    			}
    		}
    	}
    	// debug(visited);
    }

    cout << maxArea << " " << maxPerimeter;
    
    return 0;
}