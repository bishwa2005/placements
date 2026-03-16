class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(!vis[i][j]){

                    queue<vector<int>> q;
                    q.push({i,j,-1,-1});
                    vis[i][j] = 1;

                    while(!q.empty()){

                        auto node = q.front();
                        q.pop();

                        int x = node[0];
                        int y = node[1];
                        int px = node[2];
                        int py = node[3];

                        for(int k=0;k<4;k++){

                            int nx = x + drow[k];
                            int ny = y + dcol[k];

                            if(nx>=0 && ny>=0 && nx<n && ny<m &&
                               grid[nx][ny] == grid[x][y]){

                                if(!vis[nx][ny]){
                                    vis[nx][ny] = 1;
                                    q.push({nx,ny,x,y});
                                }
                                else if(nx!=px || ny!=py){
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};