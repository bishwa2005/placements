class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a=0;
        int b=0;

        unordered_set<char> st;
        int sz =0;

        while(b<s.size()){
            while(st.count(s[b])){
                st.erase(s[a]);
                a++;
            }
            st.insert(s[b]);
            sz=max(sz,b-a+1);
            b++;
        }

        return sz;
    }
};