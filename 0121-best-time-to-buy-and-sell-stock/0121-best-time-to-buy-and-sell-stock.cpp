class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        for(int i : prices){
            if(i<buy){
                buy=i;

            }
            else{
                int sell = i-buy;
                profit=max(profit,sell);
            }
        }

        return profit;
    }
};