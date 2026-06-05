class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        int nonZero = 0;
        for (int x : nums)
            if (x != 0)
                nonZero++;

        int swaps = 0;

        for (int i = 0; i < nonZero; i++) {
            if (nums[i] == 0)
                swaps++;
        }

        return swaps;
    }
};