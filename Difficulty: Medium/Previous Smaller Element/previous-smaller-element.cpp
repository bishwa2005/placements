class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> ans(n);
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(st.size() && st.top()>=arr[i])
                st.pop();
                
            if(st.size())
                ans[i]=st.top();
            else
                ans[i]=-1;
                
            st.push(arr[i]);
        }
        
        return ans;
    }
};