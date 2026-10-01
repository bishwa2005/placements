class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto c : s){
            if(c=='}' && st.top()!='{' || c==')' && st.top()!='(' || c==']' && st.top()!='[') return false;
            if(c=='}' && st.top()=='{' || c==')' && st.top()=='(' || c==']' && st.top()=='[') st.pop();
            else st.push(c);
        }

        return !st.size();
    }
};