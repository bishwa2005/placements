class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> vis(n,0);

        queue<int> q;
        q.push(start);
        vis[start]=1;

        while(q.size()){
            int node = q.front();
            q.pop();

            if(arr[node]==0) return true;

            int f = node + arr[node];
            int b = node - arr[node];

            if(f<n && !vis[f]){
                q.push(f);
                vis[f]=1;
            }
            if(b>=0 && !vis[b]){
                q.push(b);
                vis[b]=1;
            }
        }

        return false;
    }
};