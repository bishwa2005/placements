class Solution {
  public:
    void solve(stack<int> &st,int ele){
        if(st.empty() || st.top()<=ele){
            st.push(ele);
        }
        else{
            int t = st.top();
            st.pop();
            solve(st,ele);
            st.push(t);
        }
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int ele = st.top();
        st.pop();
        sortStack(st);
        solve(st,ele);
    }
};
