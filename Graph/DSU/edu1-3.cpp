/*
In a novel online game, the players fight the monsters and get experience points by joining raid teams. After defeating a monster, all players in a team gain the same experience points. Teams cannot be split up, and no one can leave a team. The only operation allowed is joining two teams together.

You are tasked with maintaining the experience points of players in the game.

### Input
The input consists of:
- The first line containing two integers `n` and `m` (1 ≤ n, m ≤ 200,000) — the number of players and the number of queries.
- The next `m` lines contain queries of three types:
  1. **join X Y**: Join the teams of players `X` and `Y` (if they are already in the same team, nothing changes).
  2. **add X V**: Add `V` (1 ≤ V ≤ 100) experience points to each player in the team containing player `X`.
  3. **get X**: Output the current number of experience points of player `X`.

Initially, each player has `0` experience points and belongs to their own team of size one.

### Output
For each **get X** query, output the current number of experience points of player `X` on a separate line.

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
    vector<int> rank; // Alternatively, use rank if preferred.
    vector<int> xpRoot, diff;

public:
    // Constructor to initialize DSU with n elements.
    DSU(int n) {
        parent.resize(n + 10);
        rank.resize(n + 10, 1); // Initial size (or size) of each set is 1.
        xpRoot.resize(n + 10, 0);
        diff.resize(n + 10, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i; // Each element is its own parent initially.
        }
    }

    int find(int x) {
        if(x == parent[x]) {
            return x;
        }
        diff[x] += diff[parent[x]];
        return parent[x] = find(parent[x]);
    }

    // Union two sets by size (or size).
    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        // Union by size: attach the smaller tree under the larger tree.
        if(rank[rootX] < rank[rootY]) {
        	swap(rootX, rootY);
        } else if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }
        parent[rootY] = rootX; // Merge the smaller tree to larger tree (based on size)
        diff[rootY] = xpRoot[rootY] - xpRoot[rootX]; // construct the diff
        return true; // Union was successful.
    }

    // Check if two elements are in the same set.
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    void addXp(int x, int v) {
        int rootX = find(x);
        xpRoot[rootX] += v;
    }

    int getXp(int x) {
        int rootX = find(x);
        return xpRoot[rootX] + diff[x];
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
        cin >> a;
        if (operationType == "join") {
        	cin >> b;
            dsu.unionSet(a, b);
        } else if (operationType == "add") {
            cin >> b;     
        	dsu.addXp(a, b);
        } else {
            cout << dsu.getXp(a) << endl;
        }
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