class Solution {
public:
    bool isPalindrome(string s) {
        string check = "";
        for(char c : s){
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
                check+=tolower(c);
        }

        string ans=check;
        reverse(ans.begin(),ans.end());

        return ans==check;
    }
};