class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        d={}
        for i in range(len(nums)):
            d[nums[i]]=0
        for i in range(len(nums)):
            d[nums[i]]+=1
        for i in d:
            if d[i]>1:
                return i
