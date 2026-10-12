class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto i : operations){
            if(i=="+"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.push(n1);
                st.push(n1+n2);
            }
            else if(i=="C"){
                st.pop();
            }
            else if(i=="D"){
                int n=st.top();
                st.push(2*n);
            }
            else {
                st.push(stoi(i));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};