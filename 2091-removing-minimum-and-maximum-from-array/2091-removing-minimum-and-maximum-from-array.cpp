class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Track both values and their corresponding indices
        int min_val = INT_MAX, max_val = INT_MIN;
        int mini = -1, maxi = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < min_val) {
                min_val = nums[i];
                mini = i;
            }
            if (nums[i] > max_val) {
                max_val = nums[i];
                maxi = i;
            }
        }
        
        // Step 2: Establish boundaries (leftmost and rightmost targets)
        int left = min(mini, maxi);
        int right = max(mini, maxi);
        
        // Step 3: Compare 3 potential elimination strategies
        int delete_from_front = right + 1;
        int delete_from_back = n - left;
        int delete_from_both = (left + 1) + (n - right);
        
        return min({delete_from_front, delete_from_back, delete_from_both});
    }
};
