class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==1)
            return;

        grid[i][j] = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int k=0;k<4;k++){
            dfs(i+drow[k], j+dcol[k], grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // remove boundary islands
        for(int i=0;i<n;i++){
            if(grid[i][0]==0) dfs(i,0,grid);
            if(grid[i][m-1]==0) dfs(i,m-1,grid);
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==0) dfs(0,j,grid);
            if(grid[n-1][j]==0) dfs(n-1,j,grid);
        }

        int count = 0;

        // count remaining islands
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }

        return count;
    }
};