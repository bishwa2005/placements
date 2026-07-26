class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();

        int tgas=0;
        int tcost=0;

        for(int i=0;i<n;i++){
            tgas+=gas[i];
            tcost+=cost[i];
        }
    // if total gas is less than total cost we cant complete
        if(tgas<tcost) return -1;

        int curr=0;
        int idx=0;

        for(int i=0;i<n;i++){
            curr+=gas[i]-cost[i];

            if(curr<0){
                idx=i+1;
                curr=0;
            }
        }

        return idx;
    }
};