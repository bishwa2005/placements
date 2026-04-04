class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;

        string result = "";

        // Traverse starting from each column
        for (int c = 0; c < cols; c++) {
            int r = 0;
            int j = c;

            // move diagonally
            while (r < rows && j < cols) {
                result += encodedText[r * cols + j];
                r++;
                j++;
            }
        }

        // remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};