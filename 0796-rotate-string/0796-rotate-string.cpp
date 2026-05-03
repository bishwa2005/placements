class Solution {
public:
    bool rotateString(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        string ans=(s1+s1);
        return ans.find(s2)!=string::npos;
    }
};