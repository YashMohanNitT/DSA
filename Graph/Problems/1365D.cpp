/*
    Problem: https://codeforces.com/contest/1365/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define yash ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define w() int t; cin >> t; while (t--)
#define int long long

const int mxN = 55;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
char grid[mxN][mxN];
bool visited[mxN][mxN];

bool insideGrid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void dfs(int i, int j) {
    if (!insideGrid(i, j) || grid[i][j] == '#' || visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        dfs(ni, nj);
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // Process the grid to block paths around 'B'
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'B') {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (insideGrid(ni, nj)) {
                        if (grid[ni][nj] == '.') {
                            grid[ni][nj] = '#';
                        }
                        if (grid[ni][nj] == 'G') {
                            cout << "No" << endl;
                            return;
                        }
                    }
                }
            }
        }
    }

    // Perform DFS from the bottom-right corner
    dfs(n - 1, m - 1);

    // Check if all 'G' cells are reachable
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'G' && !visited[i][j]) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}

int32_t main() {
    yash;
    w() {
        memset(grid, '.', sizeof(grid));
        memset(visited, 0, sizeof(visited));
        solve();
    }
    return 0;
}