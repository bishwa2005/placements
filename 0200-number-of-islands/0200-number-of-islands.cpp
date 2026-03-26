class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        for(int k=0;k<4;k++){
            int nx = i + drow[k];
            int ny = j + dcol[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]=='1'){
                dfs(nx,ny,vis,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }

        return cnt;
    }
};