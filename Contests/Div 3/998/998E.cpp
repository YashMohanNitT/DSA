/*
    https://codeforces.com/contest/2060/problem/E
*/
#include <bits/stdc++.h>

using namespace std;

#define endl            "\n"
#define all(x)          x.begin(), x.end()
#define yash            ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define w()             int t; cin >> t; while(t--)
#define rep(i, a, b)    for(int i = a; i < b; ++i)
#define vpii            vector<pair<int, int>>
#define vi              vector<int>
#define vvi             vector<vector<int>>
#define read(v, n)      rep(i, 0, n) cin >> v[i];
#define int             long long
#define ull             unsigned long long
#define lld             long double
#define out(v, n)       rep(i, 0, n) {cout << v[i] << " ";} cout << endl;

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

struct DSU {
    int n;
    vi parent, rank_;
    DSU(int n) : n(n), parent(n + 1), rank_(n + 1, 0) {
        rep(i, 1, n + 1) parent[i] = i;
    }
    int findp(int v) {
        if (parent[v] == v) return v;
        return parent[v] = findp(parent[v]);
    }
    void unite(int a, int b) {
        a = findp(a);
        b = findp(b);
        if (a == b) return;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
    }
};

int32_t main() {
    yash;
    setIO("", true);
    w() {
        int n, m1, m2;
        cin >> n >> m1 >> m2;

        vpii edgesF(m1), edgesG(m2);
        rep(i, 0, m1) cin >> edgesF[i].first >> edgesF[i].second;
        rep(i, 0, m2) cin >> edgesG[i].first >> edgesG[i].second;

        DSU dsuG(n), dsuF(n);
        for (auto &e : edgesG) {
            dsuG.unite(e.first, e.second);
        }

        vi gcomp(n + 1);
        rep(i, 1, n + 1) gcomp[i] = dsuG.findp(i);

        int remove_count = 0;
        for (auto &e : edgesF) {
            if (gcomp[e.first] != gcomp[e.second]) {
                remove_count++;
            } else {
                dsuF.unite(e.first, e.second);
            }
        }

        int add_count = 0;
        for (auto &e : edgesG) {
            if (dsuF.findp(e.first) != dsuF.findp(e.second)) {
                add_count++;
                dsuF.unite(e.first, e.second);
            }
        }

        cout << remove_count + add_count << endl;
    }

    return 0;
}
