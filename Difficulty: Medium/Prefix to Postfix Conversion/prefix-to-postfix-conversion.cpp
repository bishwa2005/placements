class Solution {
  public:
    string preToPost(string &s) {
        // code here
        int n=s.size();
        stack<string> st;
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='+' || s[i]=='*' || s[i]=='-' || s[i]=='/'){
                string o1=st.top();
                st.pop();
                string o2=st.top();
                st.pop();
                string t=o1+o2+s[i];
                st.push(t);
            }
            else{
                st.push(string(1,s[i]));
            }
        }
        
        return st.top();
    }
};