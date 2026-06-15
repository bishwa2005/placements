class Solution { 
public: 
    int cnt(vector<int> &arr, int mid) { 
        int std = 1; 
        long long mxpage = 0; 
        for(int i : arr) { 
            if(mxpage + i <= mid) {
                mxpage += i; 
            } else { 
                std += 1; 
                mxpage = i; 
            } 
        } 
        return std; 
    } 

    int findPages(vector<int> &arr, int k) { 
        int n = arr.size(); 
        if(k > n) return -1; // Fixed syntax error
        
        int low = 0; // Tracks the maximum single element
        int high = 0; // Tracks the sum of all elements
        
        for(int i : arr) { 
            low = max(low, i);
            high += i; 
        } 
        
        while(low <= high) { 
            int mid = low + (high - low) / 2; // Prevents overflow
            int students = cnt(arr, mid); 
            
            if(students > k) { 
                low = mid + 1; 
            } else { 
                high = mid - 1; // Look for a smaller maximum on the left
            } 
        } 
        return low; 
    } 
};
