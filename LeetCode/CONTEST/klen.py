class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        hash = {}
        arr = nums[::]
        arr.sort()
        arr = arr[:len(nums)-k]
        for i in arr:
            if i in hash:
                hash[i] += 1
            else:
                hash[i] = 1
        seq = []
        for i in nums:
            if i in hash:
                hash[i] -= 1
                if hash[i] == 0:
                    hash.pop(i)
            else:
                seq.append(i)
        return seq
