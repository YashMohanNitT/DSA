#include <bits/stdc++.h>
 
#define endl            "\n"
#define all(x)            x.begin(), x.end()
#define yash            ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define w()             int t; cin>>t; while(t--)
#define rep(i,a,b)      for(int i=a;i<b;++i)
#define vi                 vector<int>
#define vvi                 vector<vector<int>>
#define read(v,n)        rep(i,0,n) cin>>v[i];
#define int               long long
#define ull               unsigned long long
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;
#define pq                priority_queue
#define mod               1000000007
 
using namespace std;

// Function to perform DFS-based topological sort
void dfsTopoSort(int curr, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
    visited[curr] = 1;
    for (int next : adj[curr]) {
        if (!visited[next]) {
            dfsTopoSort(next, adj, visited, result);
        }
    }
    result.push_back(curr);  // Add the node to result after visiting all its neighbors
}

// Function to perform BFS-based (Kahn's Algorithm) topological sort
vector<int> bfsTopoSort(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n + 1, 0), result;
    
    // Calculate in-degree of each node
    for (int i = 1; i <= n; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // Add nodes with in-degree 0 to the queue
    queue<int> bfsQueue;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            bfsQueue.push(i);
        }
    }

    // Perform BFS
    while (!bfsQueue.empty()) {
        int curr = bfsQueue.front();
        bfsQueue.pop();
        result.push_back(curr);

        for (int next : adj[curr]) {
            inDegree[next]--;
            if (inDegree[next] == 0) {
                bfsQueue.push(next);
            }
        }
    }

    return result;
}

void solve() {
    // Input example: 6 nodes, 6 edges
    // Example input:
    // 6 6
    // 1 2
    // 1 3
    // 3 4
    // 5 6
    // 2 6
    // 4 6

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);  // Adjacency list for the graph
    
    // Read the directed edges
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    // DFS-based Topological Sort
    vector<int> visited(n + 1, 0), dfsResult;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfsTopoSort(i, adj, visited, dfsResult);
        }
    }
    reverse(dfsResult.begin(), dfsResult.end());  // Reverse to get correct topological order
    
    // BFS-based Topological Sort (Kahn's Algorithm)
    vector<int> bfsResult = bfsTopoSort(n, adj);

    // Output the results of both topological sorts
    cout << "DFS-based Topological Sort: ";
    out(dfsResult, dfsResult.size());

    cout << "BFS-based Topological Sort (Kahn's Algorithm): ";
    out(bfsResult, bfsResult.size());
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