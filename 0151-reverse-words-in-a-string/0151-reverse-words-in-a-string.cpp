class Solution {
public:
    string reverseWords(string s) {
        vector<string> word;
        stringstream ss(s);
        string temp;

        while(ss>>temp){
            word.push_back(temp);
        }

        string ans;
        for(int i=word.size()-1;i>=0;i--){
            if(i!=word.size()-1) ans+=' ';
            ans+=word[i];
        }

        return ans;
    }
};