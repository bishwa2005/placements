class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=0;

        for(int i : nums){
            maxi=max(i,maxi);
        }

        int ans=0;
        for(int i : nums){
            ans+=abs(maxi-i);
        }

        return ans;
    }
};