class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }

        int time=-1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};

        while(q.size()){
            auto [x,y,d] = q.front();
            q.pop();
            ti
            for(int i=0;i<4;i++){
                int nx=x+drow[i];
                int ny=y+dcol[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]!=2 && grid[nx][ny]==1){
                    vis[nx][ny]=2;
                    q.push{{nx,ny},d+1};

                }
            }    
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 2)
                    return -1;
            }
        }

        return tm;

    }
};