class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> ans(n);
        
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top()>=arr[i])
                st.pop();
            
            if(st.size())
                ans[i]=st.top();
                
            else ans[i]=-1;
            
            st.push(arr[i]);
        }
        
        return ans;
    }
};