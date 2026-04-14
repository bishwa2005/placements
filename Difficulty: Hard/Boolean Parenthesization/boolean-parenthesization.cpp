class Solution {
public:
    long long dp[201][201][2];

    long long solve(int i, int j, bool isTrue, string &s) {
        if (i > j) return 0;

        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        long long ans = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {
            long long lt = solve(i, k - 1, true, s);
            long long lf = solve(i, k - 1, false, s);
            long long rt = solve(k + 1, j, true, s);
            long long rf = solve(k + 1, j, false, s);

            if (s[k] == '&') {
                if (isTrue) {
                    ans += lt * rt;
                } else {
                    ans += lt * rf + lf * rt + lf * rf;
                }
            }

            else if (s[k] == '|') {
                if (isTrue) {
                    ans += lt * rt + lt * rf + lf * rt;
                } else {
                    ans += lf * rf;
                }
            }

            else if (s[k] == '^') {
                if (isTrue) {
                    ans += lt * rf + lf * rt;
                } else {
                    ans += lt * rt + lf * rf;
                }
            }
        }

        return dp[i][j][isTrue] = ans;
    }

    int countWays(string &s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size() - 1, true, s);
    }
};