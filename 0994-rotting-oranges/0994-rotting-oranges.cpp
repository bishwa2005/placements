class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        int tm=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},tm});
                }
            }
        }

        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};

        while(q.size()){
            auto node = q.front();
            q.pop();
            int x=node.first.first;
            int y=node.first.second;
            int t=node.second;
            tm=max(tm,t);

            for(int i=0;i<4;i++){
                int nx=x+drow[i];
                int ny=y+dcol[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                    if(!vis[nx][ny]){
                        vis[nx][ny]=1;
                        q.push({{nx,ny},t+1});
                    }
                }
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }

        return tm;
    }
};