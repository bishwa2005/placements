class Solution {
public:
    void solve(int i, int j, vector<vector<char>>& grid,
               vector<vector<int>>& vis) {

        queue<pair<int,int>> q;
        q.push({i,j});

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < grid.size() &&
                   ny >= 0 && ny < grid[0].size() &&
                   grid[nx][ny] == '1' &&
                   !vis[nx][ny]) {

                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        int cnt = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    vis[i][j] = 1;
                    solve(i,j,grid,vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};