class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        grid[x][y] = 0;

        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};

        for(int i=0;i<4;i++){
            int nx=x+drow[i];
            int ny=y+dcol[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]){
                dfs(nx,ny,grid);
            }
        }
    }    

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]==1) dfs(i,0,grid);
            if(grid[i][m-1]) dfs(i,m-1,grid);
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1) dfs(0,j,grid);
            if(grid[n-1][j]==1) dfs(n-1,j,grid);
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
            }
        }

        return cnt;
    }
};