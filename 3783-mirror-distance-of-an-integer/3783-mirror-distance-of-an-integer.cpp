class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0;
        int t=n;
        while(t>0){
            int d=t%10;
            t/=10;
            rev=(rev*10)+d;
        }
        return abs(rev-n);
    }
};