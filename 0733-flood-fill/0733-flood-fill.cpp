class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];
        if(original == color) return image;

        vector<vector<int>> vis(n, vector<int>(m,0));

        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;

        image[sr][sc] = color;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){

                int nx = x + drow[i];
                int ny = y + dcol[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m &&
                   !vis[nx][ny] && image[nx][ny]==original){

                    image[nx][ny] = color;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }

        return image;
    }
};