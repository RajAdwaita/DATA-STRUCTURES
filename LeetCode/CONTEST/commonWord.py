class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        tot = 0

        for i in words1:
            if i in words2:
                if (words1.count(i) ==1 and  words2.count(i)==1):
                    tot += 1
        return tot
