class Solution {
public:
    void bfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});

        while(q.size()){
            auto [x,y] = q.front();
            q.pop();

            int dx[]={-1,0,1,0};
            int dy[]={0,-1,0,1};

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx<m && ny<n && nx>=0 && ny>=0 && !vis[nx][ny] && grid[nx][ny]=='1'){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};