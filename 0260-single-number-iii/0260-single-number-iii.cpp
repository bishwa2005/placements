class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> st;

        for(int i : nums){
            if(st.count(i)) st.erase(i);
            else st.insert(i);
        }

        vector<int> ans;
        for(int i : st){
            ans.push_back(i);
        }

        return ans;
    }
};