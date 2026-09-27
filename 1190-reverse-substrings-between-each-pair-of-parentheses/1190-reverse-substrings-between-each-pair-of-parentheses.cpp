class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";
        
        for (char c : s) {
            if (c == '(') {
                // Save the current string built so far and start a new layer
                st.push(current);
                current = "";
            } 
            else if (c == ')') {
                // Reverse the inner string we just completed
                reverse(current.begin(), current.end());
                
                // Prepend the string from the previous layer
                current = st.top() + current;
                st.pop();
            } 
            else {
                // Accumulate regular characters
                current += c;
            }
        }
        
        return current;
    }
};
