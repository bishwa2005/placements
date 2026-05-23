class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n=len(nums)

        maj=nums[0]
        cnt=1

        for i in range(1,n):
            if(nums[i]==maj):
                cnt+=1
            if(nums[i]!=maj):
                cnt-=1
            if(cnt==0):
                cnt+=1
                maj=nums[i]
        
        return maj