class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;

        for(int i : bills){
            if(i==5) five++;

            else if(i==10){
                if(five){
                    five--;
                    ten++;
                }
                else return false;
            }

            else if(i==20){
                if(five && ten){
                    ten--;
                    five--;
                }
                else if(five>=3) five-=3;
                else return false;
            }
        }

        return true;
    }
};