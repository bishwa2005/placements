class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s1(26,0);
        vector<int> t1(26,0);
        
        if(s.size()!=t.size()) return false;

        int n=s.size();

        for(int i=0;i<n;i++){
            s1[s[i]-'a']++;
            t1[t[i]-'a']++;
        }

        return s1==t1;
    }
};