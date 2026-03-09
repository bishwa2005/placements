class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid,int &cnt){
        int n=grid.size();
        int m=grid[0].size();
        
        vis[i][j]=1;
        cnt++;

        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};

        for(int k=0;k<4;k++){
            int nx=i+drow[k];
            int ny=j+dcol[k];

            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                dfs(nx,ny,vis,grid,cnt);
            }
        }

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int final_count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int cnt=0;
                    dfs(i,j,vis,grid,cnt);
                    final_count=max(final_count,cnt);
                }
            }
        }

        return final_count;
    }
};