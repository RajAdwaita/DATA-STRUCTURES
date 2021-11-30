class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        c = 0
        for i in range(len(words)):
            for j in range(len(words[i])):
                if words[i][j] not in allowed:
                    break
                if j == len(words[i]) - 1:
                    c += 1
        return c
