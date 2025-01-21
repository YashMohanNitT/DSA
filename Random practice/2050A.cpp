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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> strings(n);
	read(strings);
	vector<int> sizes;
	int ans = 0, currSize = 0;
	for (auto &s : strings) {
		currSize += s.size();
		if (currSize > m) {
			break;
		}
		ans++;
	}
	cout << ans << endl;
}

int32_t main() {
    setIO("", true);
    w()
        solve();
    return 0;
}