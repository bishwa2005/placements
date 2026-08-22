class Solution {
public:
    int sum(int n){
        int s=0;
        while(n){
            int d=n%10;
            n/=10;
            s+=d;
        }
        return s;
    }

    int prod(int n){
        int s=1;
        while(n){
            int d=n%10;
            n/=10;
            s*=d;
        }
        return s;
    }


    bool checkDivisibility(int n) {
        int s=sum(n);
        int p=prod(n);

        return n%(s+p)==0;
    }
};