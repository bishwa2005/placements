class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> check(26,0);

        if(s.size()!=t.size()) return false;

        for(auto i : s){
            check[i-'a']++;
        }

        for(auto i : t){
            check[i-'a']--;
            if(check[i-'a']<0) return false;
        }

        return true;
    }
};