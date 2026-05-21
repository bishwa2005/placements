class Solution {
public:
    bool isBalanced(string num) {
        int odd=0;
        int even=0;

        for(int i=0;i<num.size();i++){
            // Subtract '0' to convert the character to its actual integer value
            if (i % 2 == 0) {
                even += num[i] - '0';
            } else {
                odd += num[i] - '0';
            }
        }

        return odd==even;
    }
};