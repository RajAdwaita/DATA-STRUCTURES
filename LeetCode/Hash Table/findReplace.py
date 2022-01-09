class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        words_list = []
        index = 0
        lis = []
        for word in words:
            for j in len(word):
                if word[j] in lis:
                    lis.append(index)
                else:
                    
