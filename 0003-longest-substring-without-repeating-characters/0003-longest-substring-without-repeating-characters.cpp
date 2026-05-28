class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int r=0;
        int l=0;

        int ans=0;
        while(r<s.size()){
            if(!st.count(s[r])){
                st.insert(s[r]);
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};