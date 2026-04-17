class Solution {
public:
    int reverseNum(int n) {
        int temp = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            temp = temp * 10 + d;
        }
        return temp;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // store reverse values
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            // check if current matches reverse of some previous
            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }

            // store reverse(nums[i]) for future
            int rev = reverseNum(nums[i]);
            mp[rev] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};