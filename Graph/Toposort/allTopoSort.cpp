/*
    Generating All Topological Sorts of a Directed Acyclic Graph (DAG)

    Topological sorting is an ordering of the vertices in a directed acyclic graph (DAG) such that
    for every directed edge u -> v, vertex u comes before v in the ordering. In some scenarios,
    we might be interested in finding all possible topological sorts of a DAG.

    Key Points:
    - Only DAGs: Topological sorting is only possible for Directed Acyclic Graphs (DAGs).
    - Multiple Valid Orders: A DAG can have multiple valid topological sorts.
    - Generating All Topological Sorts: We can generate all possible topological sorts using
      backtracking and recursion.

    Algorithm to Generate All Topological Sorts:
    - Compute the in-degree (number of incoming edges) for each node.
    - At each step, choose an unvisited node with in-degree 0.
    - Mark the node as visited and add it to the current result.
    - Decrease the in-degree of its neighbors by 1.
    - Recursively call the function to continue building the topological order.
    - After recursion, backtrack:
      - Unmark the node as visited.
      - Remove the node from the current result.
      - Restore the in-degree of its neighbors.
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

// Function to generate all topological sorts
void allTopoSortsUtil(vector<vector<int>>& adj, vector<int>& inDegree, vector<bool>& visited,
                      vector<int>& res, int n, vector<vector<int>>& allResults) {
    bool flag = false;  // To check if all nodes are processed

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && inDegree[i] == 0) {
            // Choose the node with in-degree 0 and not visited
            visited[i] = true;
            res.push_back(i);

            // Decrease the in-degree of adjacent nodes
            for (int neighbor : adj[i]) {
                inDegree[neighbor]--;
            }

            // Recurse to continue building the topological order
            allTopoSortsUtil(adj, inDegree, visited, res, n, allResults);

            // Backtrack: Restore the state
            visited[i] = false;
            res.pop_back();
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }

            flag = true;
        }
    }

    // If no node was added in this call, then all nodes are processed
    if (!flag) {
        allResults.push_back(res);
    }
}

void allTopoSorts(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n + 1, 0);
    vector<bool> visited(n + 1, false);
    vector<int> res;  // To store the current topological order
    vector<vector<int>> allResults;  // To store all possible topological orders

    // Calculate in-degree of each node
    for (int i = 1; i <= n; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // Start generating all topological sorts
    allTopoSortsUtil(adj, inDegree, visited, res, n, allResults);

    // Output all topological sorts
    cout << "All Possible Topological Sorts:" << endl;
    for (const auto& topoOrder : allResults) {
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }
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

        Example output:
        
        All Possible Topological Sorts:
            1 2 3 4 5 6 
            1 2 3 5 4 6 
            1 2 5 3 4 6 
            1 3 2 4 5 6 
            1 3 2 5 4 6 
            1 3 4 2 5 6 
            1 3 4 5 2 6 
            1 3 5 2 4 6 
            1 3 5 4 2 6 
            1 5 2 3 4 6 
            1 5 3 2 4 6 
            1 5 3 4 2 6 
            5 1 2 3 4 6 
            5 1 3 2 4 6 
            5 1 3 4 2 6 

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

    // Generate all topological sorts
    allTopoSorts(n, adj);
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
