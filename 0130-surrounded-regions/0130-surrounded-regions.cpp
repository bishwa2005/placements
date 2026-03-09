class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& board,vector<vector<int>>& vis){
        int n = board.size();
        int m = board[0].size();

        vis[x][y] = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        for(int i=0;i<4;i++){
            int nx = x + drow[i];
            int ny = y + dcol[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny]=='O' && !vis[nx][ny]){
                dfs(nx,ny,board,vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        // left and right boundary
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis);
            }
        }

        // top and bottom
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,board,vis);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,board,vis);
            }
        }

        // convert surrounded regions
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};