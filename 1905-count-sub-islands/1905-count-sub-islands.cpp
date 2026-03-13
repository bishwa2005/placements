class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int n=grid2.size();
        int m=grid2[0].size();

        if(i<0 || j<0 || i>=n || j>=m || grid2[i][j]==0)
            return true;

        grid2[i][j] = 0;

        bool isSubIsland = true;

        if(grid1[i][j] == 0)
            isSubIsland = false;

        bool up = dfs(i-1,j,grid1,grid2);
        bool down = dfs(i+1,j,grid1,grid2);
        bool left = dfs(i,j-1,grid1,grid2);
        bool right = dfs(i,j+1,grid1,grid2);

        return isSubIsland && up && down && left && right;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1)
                    if(dfs(i,j,grid1,grid2))
                        count++;
            }
        }

        return count;


    }
};