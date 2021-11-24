class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        final = []
        for i in arr2:
            for j in arr1:
                if j == i:
                    final.append(j)

        left = []
        for i in arr1:
            if i not in arr2:
                left.append(i)
        left.sort()
        final += left
        return final
