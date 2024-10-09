/*
    Topological Sorting in Directed Acyclic Graphs (DAGs)

    Topological sorting is a way to order the nodes (or vertices) in a directed acyclic graph (DAG)
    such that for every directed edge u -> v, node u comes before node v in the ordering.
    Topological sorting is useful in scenarios like dependency resolution, task scheduling, and
    precedence constraints, where certain tasks must be performed before others.

    Key Points:
    - Only DAGs: Topological sorting can only be performed on Directed Acyclic Graphs (DAGs).
      If the graph contains a cycle, topological sorting is not possible.
    - Multiple Valid Orders: There can be multiple valid topological sorts for a graph,
      depending on the structure of the graph.

    Common Methods to Perform Topological Sort:

    1. DFS-based Topological Sort
       Algorithm:
       - Use Depth-First Search (DFS) to visit all nodes.
       - For each node, recursively visit all its unvisited neighbors.
       - After visiting all neighbors, add the node to a result stack or list.
       - Once all nodes are processed, reverse the result to get the topological order.

       Key Points:
       - Nodes are added to the result after all their dependencies (outgoing edges) are processed.
       - Reversing the result gives the correct topological order.

    2. BFS-based Topological Sort (Kahn’s Algorithm)
       Algorithm:
       - Compute the in-degree (number of incoming edges) for each node.
       - Initialize a queue with all nodes having in-degree 0 (no dependencies).
       - While the queue is not empty:
         - Remove a node from the queue and add it to the result.
         - For each neighbor of the node:
           - Decrease the in-degree of the neighbor by 1.
           - If the in-degree of the neighbor becomes 0, add it to the queue.

       Key Points:
       - Nodes with no incoming edges are processed first.
       - No need to reverse the result, as the order is built correctly.
*/

#include <bits/stdc++.h>

#define endl            "\n"
#define all(x)          x.begin(), x.end()
#define yash            ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i,a,b)      for(int i=a;i<b;++i)
#define vi              vector<int>
#define vvi             vector<vector<int>>
#define read(v,n)       rep(i,0,n) cin>>v[i];
#define int             long long
#define out(v,n)        rep(i,0,n) {cout<<v[i]<<" ";}cout<<endl;
#define mod             1000000007

using namespace std;

// Function to perform DFS-based topological sort
void dfsTopoSort(int curr, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
    visited[curr] = 1;  // Mark the current node as visited
    for (int next : adj[curr]) {  // Iterate over all the adjacent nodes
        if (!visited[next]) {
            dfsTopoSort(next, adj, visited, result);  // Recursively visit unvisited neighbors
        }
    }
    result.push_back(curr);  // Add the node to result after visiting all its neighbors
}

// Function to perform BFS-based topological sort (Kahn's Algorithm)
vector<int> bfsTopoSort(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n + 1, 0);  // Initialize in-degree of all nodes to 0
    vector<int> result;  // To store the topological order
    
    // Calculate in-degree of each node
    for (int i = 1; i <= n; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;  // Increment in-degree for each incoming edge
        }
    }

    // Initialize a queue and add all nodes with in-degree 0
    queue<int> bfsQueue;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            bfsQueue.push(i);  // Node with no incoming edges
        }
    }

    // Perform BFS
    while (!bfsQueue.empty()) {
        int curr = bfsQueue.front();
        bfsQueue.pop();
        result.push_back(curr);  // Add current node to the topological order

        // Decrease the in-degree of neighbor nodes by 1
        for (int next : adj[curr]) {
            inDegree[next]--;
            if (inDegree[next] == 0) {
                bfsQueue.push(next);  // If in-degree becomes 0, add to queue
            }
        }
    }

    return result;
}

void solve() {
    /*
        Example Input:
        6 6
        1 2
        1 3
        3 4
        5 6
        2 6
        4 6

        Explanation:
        - Nodes: 1 to 6
        - Edges: (1->2), (1->3), (3->4), (5->6), (2->6), (4->6)
        - The graph represents tasks with dependencies.
    */

    int n, m;
    cin >> n >> m;  // n: number of nodes, m: number of edges
    
    vector<vector<int>> adj(n + 1);  // Adjacency list for the graph (1-based indexing)
    
    // Read the directed edges
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);  // Add an edge from 'from' to 'to'
    }

    // DFS-based Topological Sort
    vector<int> visited(n + 1, 0);  // Keep track of visited nodes
    vector<int> dfsResult;  // To store the topological order
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
