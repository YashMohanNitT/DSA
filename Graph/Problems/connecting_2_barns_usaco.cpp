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

void dfs(int curr, int totalGroups, vector<int> &component, vector<vector<int>> &adj) {
	component[curr] = totalGroups;
	for (int next : adj[curr]) {
		if (component[next] == 0) {
			dfs(next, totalGroups, component, adj);
		}
	}
}

int findcost(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0, cost = LLONG_MAX;  // Use LLONG_MAX for precision
    while (i < a.size() && j < b.size()) {
        cost = min(cost, (a[i] - b[j]) * (a[i] - b[j]));
        if (a[i] <= b[j]) i++;
        else j++;
    }
    return cost;
}


int32_t main() {
    // setIO("", true);
    w() {
    	int n, m;
    	cin >> n >> m;
    	vector<int> component(n + 1, 0);
    	vector<vector<int>> adj(n + 1);
    	for (int i = 0; i < m; ++i) {
    		int a, b;
    		cin >> a >> b;
    		adj[a].push_back(b);
    		adj[b].push_back(a);
    	}
    	int totalGroups = 0;
    	for (int cow = 1; cow <= n; ++cow) {
    		if (component[cow] == 0) {
    			totalGroups++;
    			dfs(cow, totalGroups, component, adj);
    		}
    	}

    	if(component[1] == component[n]) {
    		cout << 0 << endl;
    		continue;
    	}
    	
    	vector<vector<int>> cowGroup(totalGroups + 1);
    	for (int cow = 1; cow <= n; ++cow) {
    		cowGroup[component[cow]].push_back(cow);
    	}

    	vector<int> start_component = cowGroup[component[1]];
		vector<int> end_component = cowGroup[component[n]];

		// Initialize distance vectors with infinity
		vector<int> dist1(totalGroups + 1, INT_MAX);
		vector<int> dist2(totalGroups + 1, INT_MAX);

		// Calculate minimum distances to start_component
		int a = 0;
		for (int i = 1; i <= n; i++) {
			int dist = abs(start_component[a] - i);
			while (a < start_component.size() - 1 &&
			       abs(start_component[a + 1] - i) < dist) {
				a++;
			}
			dist1[component[i]] = min(dist1[component[i]], dist);
		}

		// Calculate minimum distances to end_component
		int b = 0;
		for (int i = 1; i <= n; i++) {
			int dist = abs(end_component[b] - i);
			while (b < end_component.size() - 1 &&
			       abs(end_component[b + 1] - i) < dist) {
				b++;
			}
			dist2[component[i]] = min(dist2[component[i]], dist);
		}

		// Compute the result by finding the minimum sum of squared distances
		int res = LLONG_MAX;
		for (int i = 1; i <= totalGroups; i++) {
			res = min(res, 1LL * dist1[i] * dist1[i] + 1LL * dist2[i] * dist2[i]);
		}
		cout << res << '\n';
    }
    return 0;
}