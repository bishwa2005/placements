class Solution {
public:
    void solve(int open, int close, int n, string &s, vector<string> &ans) {
        
        // Length becomes 2*n
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // We can add '(' if we haven't used all n opening brackets
        if (open < n) {
            s += '(';
            solve(open + 1, close, n, s, ans);
            s.pop_back();
        }

        // We can add ')' only if there are unmatched '('
        if (close < open) {
            s += ')';
            solve(open, close + 1, n, s, ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";

        solve(0, 0, n, s, ans);

        return ans;
    }
};