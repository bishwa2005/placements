class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    vis[i][j]==2;
                    q.push({{i,j},0});
                }
            }
        }
        
        int tm=0;
        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,-1,0,1};
        
        while(q.size()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            tm=max(t,tm);
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && mat[nrow][ncol]==1){
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        
        return tm;
    }
};