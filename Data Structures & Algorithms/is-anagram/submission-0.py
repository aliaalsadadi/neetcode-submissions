class Solution:
    @staticmethod
    def generateDict(s: str) -> dict:
        s_map = {}
        for c in s:
            if c not in s_map:
                s_map[c] = 1
            else:
                s_map[c] += 1
        return s_map
    def isAnagram(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False
        s_map = self.generateDict(s)
        t_map = self.generateDict(t)
        return t_map == s_map

        
        