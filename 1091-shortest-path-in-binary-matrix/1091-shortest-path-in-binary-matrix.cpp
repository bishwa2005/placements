class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1) return -1;

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(n,0));

        q.push({{0,0},1});
        vis[0][0] = 1;

        int drow[] = {-1,-1,-1,0,0,1,1,1};
        int dcol[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();

            if(x == n-1 && y == n-1) return d;

            for(int i=0;i<8;i++){
                int nx = x + drow[i];
                int ny = y + dcol[i];

                if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny] && grid[nx][ny]==0){
                    vis[nx][ny] = 1;
                    q.push({{nx,ny}, d+1});
                }
            }
        }

        return -1;
    }
};