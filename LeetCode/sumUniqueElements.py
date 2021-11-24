class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        final=[]
        for i in range(len(nums)):
            if nums.count(nums[i])==1:
                final.append(nums[i])
        return sum(final)
        
