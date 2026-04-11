class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int i = s.size() - 1;

        // skip trailing spaces safely
        while (i >= 0 && s[i] == ' ') i--;

        // count last word
        while (i >= 0 && s[i] != ' ') {
            cnt++;
            i--;
        }

        return cnt;
    }
};