class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=INT_MAX;
        int mx=INT_MIN;

        for(int i : nums){
            if(i>mx) mx=i;
            if(i<mn) mn=i; 
        }

        int ans=1;
        for(int i=1;i<=mn;i++){
            if(mx%i==0 && mn%i==0) ans=i;
        }

        return ans;
    }
};