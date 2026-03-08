class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){   // start from all land
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        if(q.empty() || q.size() == n*n) return -1;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        int ans = 0;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(dist[nx][ny] > dist[x][y] + 1){
                        dist[nx][ny] = dist[x][y] + 1;
                        ans = max(ans, dist[nx][ny]);
                        q.push({nx,ny});
                    }
                }
            }
        }

        return ans;
    }
};