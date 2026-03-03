class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};

        vis[i][j]=1;

        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];

            if(nrow>=0 && nrow<n && 
               ncol>=0 && ncol<m && 
               grid[nrow][ncol]=='1' && 
               !vis[nrow][ncol]){
                
                dfs(nrow,ncol,vis,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }                          

        return cnt;
    }
};