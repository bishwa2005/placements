class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];  // Initialize with the first possible triplet

        for (int i = 0; i < n - 2; i++) {
            int s = i + 1;
            int e = n - 1;

            while (s < e) {
                int current_sum = nums[i] + nums[s] + nums[e];

                if (abs(current_sum - target) < abs(ans - target)) {
                    ans = current_sum;
                }

                if (current_sum < target) {
                    ++s;
                } else if (current_sum > target) {
                    --e;
                } else {
                    // Exact match
                    return current_sum;
                }
            }
        }
        return ans;
    }
};
