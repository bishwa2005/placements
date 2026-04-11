class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map <int,vector<int>> mp;

        int n=nums.size();
        if(n<=2) return -1;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int mini = INT_MAX;

        for(auto &it : mp){
            vector<int> temp = it.second;
            if(temp.size()>=3){
                for(int i=0;i<temp.size()-2;i++){
                    int a=temp[i];
                    int b=temp[i+1];
                    int c=temp[i+2];
                    
                    int f= 2*(max({a,b,c})-min({a,b,c}));

                    mini = min(mini,f);
                }

            }
        }

        if(mini == INT_MAX) return -1;
        return mini;
    }
};