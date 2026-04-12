class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(), strs.end());

        int n = strs.size() - 1;
        string ans = "";
        int i = 0;

        while(i < strs[0].size() && i < strs[n].size()) {
            if(strs[0][i] == strs[n][i]) {
                ans += strs[0][i];
            } else {
                break;  
            }
            i++;  
        }

        return ans;
    }
};