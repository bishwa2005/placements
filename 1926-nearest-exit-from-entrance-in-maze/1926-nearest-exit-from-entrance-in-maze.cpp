class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,(vector<int>(m,0)));

        vis[entrance[0]][entrance[1]]=1;
        q.push({{entrance[0],entrance[1]},0});

        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};

        while(q.size()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int d=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+drow[i];
                int ny=y+dcol[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && maze[nx][ny]=='.'){
                    if(nx==n-1 || ny==m-1 || nx==0 || ny==0)
                        return d+1;

                    vis[nx][ny]=1;
                    q.push({{nx,ny},d+1});
                }
            }            
        }

        return -1;
    }
};