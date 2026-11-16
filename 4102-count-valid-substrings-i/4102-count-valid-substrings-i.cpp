class Solution {
public:
    long long countValidSubstrings(string s) {
        long long cnt = 0;
        int n = s.size();
        cnt += n; // All single-character substrings are valid

        int i = 0;
        int j = 1;
        while (j < n) {
            if ((j - i + 1) >= 3 && s.substr(j - 2, 3) == "abc") {
                // Shrink window so it starts at 'b' of "abc"
                i = j - 1; 
            } else {
                // Add all valid substrings of length >= 2 ending at j
                cnt += (j - i);
                j++;
            }
        }

        return cnt;
    }
};
