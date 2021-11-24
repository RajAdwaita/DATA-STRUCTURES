class Solution:
    def findWords(self, words: List[str]) -> List[str]:

        row1 = ['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P']
        row2 = ['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L']
        row3 = ['z', 'x', 'c', 'v', 'b', 'n', 'm',
                'Z', 'X', 'C', 'V', 'B', 'N', 'M']

        final = []
        for i in range(len(words)):
            r1 = 0
            r2 = 0
            r3 = 0
            for j in words[i]:
                if j in row1:
                    r1 += 1
                elif j in row2:
                    r2 += 1
                else:
                    r3 += 1
            if(r1 == len(words[i]) or r2 == len(words[i]) or r3 == len(words[i])):
                final.append(words[i])
        return final
