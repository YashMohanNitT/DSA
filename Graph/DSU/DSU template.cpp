/*
	Implement disjoint sets (union-find) data structure. 
You have to perform queries of two types:

1) union u v
   Unite the two sets that contain u and v, respectively.

2) get u v
   Check whether two elements u and v belong to the same set.

Input Format:
--------------
The first line of the input contains two integers n and m (1 ≤ n, m ≤ 10^5) —
the number of elements (numbered from 1 to n) and the number of queries.
The next m lines contain queries, one per line.

For a query "union", the line looks like:
    union u v
(1 ≤ u, v ≤ n)

For a query "get", the line looks like:
    get u v
(1 ≤ u, v ≤ n)

Output Format:
--------------
For each "get" query, output one line with "YES" if the elements u and v 
are in the same set, and "NO" otherwise.

Example 1:
-----------
Input:
4 4
union 1 2
union 1 3
get 1 4
get 2 3

Output:
NO
YES

Example 2:
-----------
Input:
5 5
union 1 2
union 2 3
get 1 4
union 3 4
get 1 4

Output:
NO
YES

Example 3:
-----------
Input:
5 4
union 1 2
union 2 3
get 1 3
get 4 5

Output:
YES
NO
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
 
class DSU {
private:
	int components;
	int maxSize;
    vector<int> parent;
    vector<int> size; // Alternatively, use rank if preferred.

public:
    // Constructor to initialize DSU with n elements.
    DSU(int n) {
        parent.resize(n + 10);
        size.resize(n + 10, 1); // Initial size (or size) of each set is 1.
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Each element is its own parent initially.
        }
        components = n;
        maxSize = 1;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression.
        }
        return parent[x];
    }

    // Union two sets by size (or size).
    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        // Union by size: attach the smaller tree under the larger tree.
        if(size[rootX] < size[rootY]) {
        	swap(rootX, rootY);
        }
        
        parent[rootY] = rootX; // Merge the smaller tree to larger tree (based on size)
        size[rootX] += size[rootY];
        maxSize = max(maxSize, size[rootX]);
        components--;
        return true; // Union was successful.
    }

    // Check if two elements are in the same set.
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int getComponents() {
    	return components;
    }

    int getMaxSize() {
    	return maxSize;
    }
};

void solve() {
	int n, m;
    cin >> n >> m;
	DSU dsu(n);
	string operationType;
	int a, b;
    for(int i = 0; i < m; ++i) {
        cin >> operationType;
        cin >> a >> b;
        if (operationType == "union") {
        	dsu.unionSet(a, b);
        } else {
        	bool sameSet = dsu.connected(a, b);
        	cout << ((sameSet) ? "YES" : "NO") << endl;
        }
        // cout << dsu.getComponents() << " " << dsu.getMaxSize() << endl;
    }
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