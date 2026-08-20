class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxi=0;
        
        for(int i : st){
            if(st.count(i-1)) continue;
            else{
                int cnt=1;
                int curr=i;
                while(st.count(curr+1)){
                    cnt++;
                    curr++;
                }
                maxi=max(maxi,cnt);
            }
        }

        return maxi;
    }
};