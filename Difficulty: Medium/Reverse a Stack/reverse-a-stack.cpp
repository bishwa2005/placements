class Solution {
  public:
    void solve(stack<int> &st,int n){
        if(st.empty()){
            st.push(n);
            return;
        }
        
        int top = st.top();
        st.pop();              
        
        solve(st,n);
        
        st.push(top);
    }

    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
        
        int top = st.top();
        st.pop();
        
        reverseStack(st);
        
        solve(st,top);
    }
};