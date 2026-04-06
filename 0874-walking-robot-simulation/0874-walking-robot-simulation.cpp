class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;

        for(auto it : obstacles){
            st.insert({it[0], it[1]});
        }

        vector<pair<int,int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} };

        int x = 0, y = 0, d = 0;
        int ans = 0;

        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == -1)
                d = (d + 1) % 4;

            else if(commands[i] == -2)
                d = (d + 3) % 4;

            else {
                for(int j = 0; j < commands[i]; j++){
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    if(st.count({nx, ny})) break;

                    x = nx;
                    y = ny;

                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};