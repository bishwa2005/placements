class Solution {
  public:
    void solve(stack<int> &st,int t){
        if(st.empty() || st.top()<=t){
            st.push(t);
        }
        else{
            int tp=st.top();
            st.pop();
            solve(st,t);
            st.push(tp);
        }
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int t = st.top();
        st.pop();
        sortStack(st);
        solve(st,t);
    }
};
