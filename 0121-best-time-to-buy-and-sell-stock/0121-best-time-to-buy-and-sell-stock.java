class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        int profit=0;
        int curr=prices[0];

        for(int i=1;i<n;i++){
            if(prices[i]<curr){
                curr=prices[i];
            }
            else{
                int sell=prices[i]-curr;
                profit=Math.max(profit,sell);
            }
        }

        return profit;
    }
}