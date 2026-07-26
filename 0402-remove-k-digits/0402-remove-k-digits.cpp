class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;

        for(char ch : num){
            while(s.size() && s.back()>ch && k>0){
                s.pop_back();
                k--;
            }
            s.push_back(ch);
        }

        while(s.size() && k>0){
            s.pop_back();
            k--;
        }

        int i=0;
        while(i<s.size() && s[i]=='0'){
            i++;
        }

        string ans=s.substr(i);

        return (ans.size()) ? ans : "0";
    }
};