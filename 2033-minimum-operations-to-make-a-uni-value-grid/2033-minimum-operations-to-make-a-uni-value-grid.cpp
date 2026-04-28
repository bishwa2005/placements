class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        for(auto row : grid){
            for(int val : row){
                arr.push_back(val);
            }
        }

        sort(arr.begin(), arr.end());

        int target = arr[arr.size()/2];   // median
        int cnt = 0;

        for(int num : arr){
            if(abs(num - target) % x != 0)
                return -1;

            cnt += abs(num - target) / x;
        }

        return cnt;
    }
};