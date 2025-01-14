/*
You are given an undirected graph and a sequence of operations of two types:

1. **cut u v**: Remove the edge `u-v` from the graph.
2. **ask u v**: Check whether vertices `u` and `v` belong to the same connected component.

Initially, the graph contains `m` edges. After all the operations are performed, the graph will contain no edges. Your task is to find the result of each operation of type **ask**.

### Input
The input consists of:
- The first line containing three integers `n`, `m`, and `k` (1 ≤ n ≤ 50,000, 0 ≤ m ≤ 100,000, m ≤ k ≤ 150,000) — the number of vertices, the number of edges, and the number of operations, respectively.
- The next `m` lines, each containing two integers `u` and `v` (1 ≤ u, v ≤ n) — the endpoints of edge `i`. Vertices are numbered from 1 to `n`, and the graph has no loops or multiple edges.
- The next `k` lines describe an operation in the following format:
  - **"cut u v"** (1 ≤ u, v ≤ n): Remove the edge between vertices `u` and `v`.
  - **"ask u v"** (1 ≤ u, v ≤ n): Check whether vertices `u` and `v` are in the same component.

Each edge is mentioned in a **cut** operation exactly once.

### Output
For each **ask u v** operation, output:
- `"YES"` if vertices `u` and `v` are in the same connected component.
- `"NO"` otherwise.

The answers should be printed in the same order as the corresponding **ask** operations in the input.

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
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n + 1); 
        rank.resize(n + 1, 1); 
        for (int i = 1; i <= n; ++i) {
            parent[i] = i; 
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX; 
        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class operation {
public:
    string operationType;
    int a, b;
    operation(string ot, int aa, int bb) {
        operationType = ot;
        a = aa;
        b = bb;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
    }

    vector<string> answers;
    vector<operation> operations;
    string ops;

    for (int i = 0; i < k; i++) {
        cin >> ops >> u >> v;
        operations.push_back(operation(ops, u, v));
    }

    DSU dsu(n);

    for (int i = k - 1; i >= 0; i--) {
        if (operations[i].operationType == "cut") {
            dsu.unionSet(operations[i].a, operations[i].b);
        } else {
            if (dsu.connected(operations[i].a, operations[i].b)) {
                answers.push_back("YES");
            } else {
                answers.push_back("NO");
            }
        }
    }
    // if(answers.empty()) {
    //     return;
    // }
    for (int i = answers.size() - 1; i >= 0; --i) {
        cout << answers[i] << "\n";
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