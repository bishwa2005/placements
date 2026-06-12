class Solution { 
    public int findPeakElement(int[] nums) { 
        int n = nums.length; 
        
        // Handle boundary conditions and single-element arrays safely
        if (n == 1) return 0; 
        if (nums[0] > nums[1]) return 0; 
        if (nums[n-1] > nums[n-2]) return n - 1; // Fixed: return index, not value
        
        // Shrink search space to safe boundaries [1, n-2]
        int lo = 1; 
        int hi = n - 2; 
        
        while (lo <= hi) { 
            int mid = lo + (hi - lo) / 2; // Prevents integer overflow
            
            // Peak condition satisfied
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid; 
            }
            // If rising to the right, a peak exists on the right
            else if (nums[mid] < nums[mid+1]) {
                lo = mid + 1; 
            }
            // If falling to the right (or a valley), a peak exists on the left
            else {
                hi = mid - 1; 
            }
        } 
        return -1; 
    } 
}
