class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int> st;
        for(int i: nums){
            st.insert(i);
        }

        vector<int> ans;
        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i : nums){
            if(i>maxi) maxi=i;
            if(i<mini) mini=i;
        }

        for(int i=mini;i<=maxi;i++){
            if(!st.count(i)) ans.push_back(i);
        }

        return ans;
    }
};