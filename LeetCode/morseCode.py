class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                 "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
        final = []
        for i in words:
            s = ""

            for j in i:
                s += morse[ord(j)-97]
            if(s not in final):
                final.append(s)
        set(final)
        return len(final)
