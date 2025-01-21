/*
    https://codeforces.com/contest/2060/problem/A
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

int f(int a, int b, int c) {
	return a + b == c;
}
int32_t main() {
    setIO("", true);
    w() {
    	int a1, a2, a3, a4, a5;
    	cin >> a1 >> a2 >> a4 >> a5;
    	int ans = 0, ans2 = 0;
    	a3 = a1 + a2;
    	ans += f(a1, a2, a3);
    	ans += f(a2, a3, a4);
    	ans += f(a3, a4, a5);
    	a3 = a5 - a4;
    	ans2 += f(a1, a2, a3);
    	ans2 += f(a2, a3, a4);
    	ans2 += f(a3, a4, a5);
    	cout << max(ans, ans2) << endl
    }



    
    return 0;
}