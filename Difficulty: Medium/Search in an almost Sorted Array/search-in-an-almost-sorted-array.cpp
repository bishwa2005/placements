// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int l = 0, r = arr.size() - 1;

        while (r >= l) {
            int mid = l + (r - l) / 2;
            
            if (arr[mid] == target) 
                return mid;
            if (mid > l && arr[mid - 1] == target) 
                return mid - 1;
            if (mid < r && arr[mid + 1] == target) 
                return mid + 1;
    
            if (arr[mid] > target) 
                r = mid - 2;
    
            else 
                l = mid + 2;
        }
        
        return -1;
    }
};