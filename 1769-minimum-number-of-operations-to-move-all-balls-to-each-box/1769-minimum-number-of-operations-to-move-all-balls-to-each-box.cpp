class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> left(n, 0), right(n, 0), ans(n);

        int balls = 0;
        int cost = 0;

        // Left to Right
        for (int i = 0; i < n; i++) {
            left[i] = cost;
            if (boxes[i] == '1')
                balls++;
            cost += balls;
        }

        // Right to Left
        balls = 0;
        cost = 0;

        for (int i = n - 1; i >= 0; i--) {
            right[i] = cost;
            if (boxes[i] == '1')
                balls++;
            cost += balls;
        }

        // Combine
        for (int i = 0; i < n; i++)
            ans[i] = left[i] + right[i];

        return ans;
    }
};