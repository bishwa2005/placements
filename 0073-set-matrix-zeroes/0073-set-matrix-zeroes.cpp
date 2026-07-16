class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        bool first_row = false;
        bool first_col = false;
        
        // 1. Check if the first row originally contains any zeros
        for(int j = 0; j < n; j++) {
            if(mat[0][j] == 0) {
                first_row = true;
                break;
            }
        }
        
        // 2. Check if the first column originally contains any zeros
        for(int i = 0; i < m; i++) {
            if(mat[i][0] == 0) {
                first_col = true;
                break;
            }
        }
        
        // 3. Use the first row and column to store markers for the rest of the matrix
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        // 4. Zero out cells based on the markers stored in the first row and column
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
        
        // 5. Finally, zero out the first row if needed
        if(first_row) {
            for(int j = 0; j < n; j++) {
                mat[0][j] = 0;
            }
        }
        
        // 6. Finally, zero out the first column if needed
        if(first_col) {
            for(int i = 0; i < m; i++) {
                mat[i][0] = 0;
            }
        }
    }
};
