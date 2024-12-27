#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; // A large value to represent unreachable cells
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // U, D, L, R

struct State {
    int x, y, time;
};

int n, m;
vector<string> grid;
vector<vector<int>> monster_time, player_time;
pair<int, int> start;
queue<State> q_monsters, q_player;

// Check if a position is inside the grid and not a wall
bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

// Multi-source BFS to calculate minimum time for monsters to reach each cell
void bfs_monsters() {
    while (!q_monsters.empty()) {
        auto [x, y, time] = q_monsters.front();
        q_monsters.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (is_valid(nx, ny) && monster_time[nx][ny] == INF) {
                monster_time[nx][ny] = time + 1;
                q_monsters.push({nx, ny, time + 1});
            }
        }
    }
}

// BFS for the player to check if reaching a boundary is possible
bool bfs_player(string &path) {
    while (!q_player.empty()) {
        auto [x, y, time] = q_player.front();
        q_player.pop();

        // Check if we've reached the boundary
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            // If we've reached the boundary, trace the path back
            vector<char> directions_path;
            while (player_time[x][y] != 0) {
                for (int d = 0; d < 4; ++d) {
                    int nx = x - directions[d].first;
                    int ny = y - directions[d].second;
                    if (is_valid(nx, ny) && player_time[nx][ny] == player_time[x][y] - 1) {
                        if (d == 0) directions_path.push_back('U');
                        if (d == 1) directions_path.push_back('D');
                        if (d == 2) directions_path.push_back('L');
                        if (d == 3) directions_path.push_back('R');
                        x = nx;
                        y = ny;
                        break;
                    }
                }
            }
            reverse(directions_path.begin(), directions_path.end());
            path = string(directions_path.begin(), directions_path.end());
            return true;
        }

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (is_valid(nx, ny) && player_time[nx][ny] == INF && (time + 1 < monster_time[nx][ny])) {
                player_time[nx][ny] = time + 1;
                q_player.push({nx, ny, time + 1});
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    monster_time.assign(n, vector<int>(m, INF));
    player_time.assign(n, vector<int>(m, INF));

    // Initialize queues for BFS
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                q_monsters.push({i, j, 0});
                monster_time[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    // Step 1: Multi-source BFS for monsters
    bfs_monsters();

    // Step 2: BFS for player
    q_player.push({start.first, start.second, 0});
    player_time[start.first][start.second] = 0;

    string path;
    if (bfs_player(path)) {
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
