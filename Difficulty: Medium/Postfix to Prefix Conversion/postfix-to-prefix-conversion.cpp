class Solution {
  public:
    string postToPre(string s) {
        // code here
        int n=s.size();
        stack<string> st;
        
        for(int i=0;i<n;i++){
            if(s[i]=='+' || s[i]=='*' || s[i]=='/' || s[i]=='-'){
                string o1=st.top();
                st.pop();
                string o2=st.top();
                st.pop();
                string t=s[i]+o2+o1;
                st.push(t);
            }
            else st.push(string(1,s[i]));
        }
        
        return st.top();
    }
};