class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr=0
        max_sum=float("-inf")
        for i in nums:
            curr+=i
            max_sum=max(max_sum,curr)
            if(curr<0):
                curr=0
        
        return max_sum
        