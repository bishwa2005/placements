class Solution {
  public:
    int find(int n){
        if(n%4==1) return 1;
        else if(n%4==2) return n+1;
        else if(n%4==3) return 0;
        else if(n%4==0) return n;
    }
    
    int findXOR(int l, int r) {
        // code here
        int range1 = find(l-1);
        int range2 = find(r);
        
        return range1^range2;
    }
};