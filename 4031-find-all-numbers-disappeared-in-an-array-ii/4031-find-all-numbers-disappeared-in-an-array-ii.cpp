class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> st(nums.begin(),nums.end());

        vector<int> miss;


        for(int i=lower;i<=upper;i++){
            if(!st.count(i)) miss.push_back(i);
        }

        int n=miss.size();

        vector<vector<int>> ans;

        int i=0;
        for(;i<miss.size();i++){
            int s=miss[i];
            

            while (i + 1 < n && miss[i] + 1 == miss[i + 1]) {
                i++;
            }

            int e=miss[i];
            ans.push_back({s,e});
        }

        return ans;
    }
};