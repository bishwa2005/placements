class Solution {
  public:
    string removeDuplicates(string& s) {
        // code here.
        string ans="";
        
        for(int i=0;i<s.size();i++){
            if(i!=s.size()-1 && s[i]==s[i+1]) continue;
            ans+=s[i];
        }
        
        return ans;
    }
};