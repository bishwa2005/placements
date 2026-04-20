class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        int m=matrix.size();
        int n=matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (int i = 0; i < m; i++) {
            int j = 0;
            int k = n - 1;
            while (j < k) {
                swap(matrix[i][j], matrix[i][k]);
                j++;
                k--;
            }
        }


    }
};