class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr=prices[0]
        profit=0

        for i in prices:
            if(i<curr):
                curr=i
            else:
                sell=i-curr
                profit=max(profit,sell)       

        return profit