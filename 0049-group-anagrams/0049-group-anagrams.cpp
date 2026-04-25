class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(auto st : strs){
            string it = st;
            sort(it.begin(),it.end());
            mp[it].push_back(st);
        }

        vector<vector<string>> ans;

        for(auto vec : mp){
            ans.push_back(vec.second);
        }

        return ans;
    }
};