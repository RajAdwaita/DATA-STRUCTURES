class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:

        d = {}
        s = s.split()
        if len(pattern) != len(s):
            return False
        for i in range(len(pattern)):
            if pattern[i] not in d:
                if s[i] in d.values():
                    return False
                d[pattern[i]] = s[i]
            else:
                if d[pattern[i]] != s[i]:
                    return False
        return True
