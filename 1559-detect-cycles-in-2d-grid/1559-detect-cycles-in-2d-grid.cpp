class Solution {
public:
    bool check(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;
        q.push({i, j, -1, -1});
        vis[i][j] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int r = node[0];
            int c = node[1];
            int pr = node[2];
            int pc = node[3];

            for (int k = 0; k < 4; k++) {
                int nx = r + drow[k];
                int ny = c + dcol[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == grid[r][c]) {
                    if (!vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny, r, c});
                    } 
                    else if (nx != pr || ny != pc) {
                        return true; // cycle detected
                    }
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (check(grid, i, j, vis)) return true;
                }
            }
        }
        return false;
    }
};