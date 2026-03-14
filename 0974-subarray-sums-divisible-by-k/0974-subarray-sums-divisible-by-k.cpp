class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int prefix = 0;

        unordered_map<int,int> mp;
        mp[0]=1;

        for(int num : nums){
            prefix+=num;
            int ans = prefix%k;

            if(ans<0)
                ans+=k;

            if(mp.find(ans)!=mp.end()){
                count+=mp[ans];
                mp[ans]+=1;
            }
            else{
                mp[ans]=1;
            }
        }

        return count;
    }
};