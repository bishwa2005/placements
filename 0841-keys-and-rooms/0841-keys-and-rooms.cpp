class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<int> vis(n,0);

        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto key : rooms[node]){
                if(!vis[key]){
                    vis[key] = 1;
                    q.push(key);
                }
            }
        }

        for(int i : vis){
            if(i == 0) return false;
        }

        return true;
    }
};