class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        maxm = floor(len(nums)//2)
        d = {}
        s = set(nums)
        for i in s:
            d[i] = nums.count(i)
        for i in d:
            if(d[i] > maxm):
                return i
