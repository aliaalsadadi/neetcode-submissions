from collections import defaultdict
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        countS = defaultdict(int)
        countT = defaultdict(int)
        for c in t:
            countT[c] += 1
        minstr, minLen = "", float("infinity")
        have, need = 0, len(countT)
        l = 0
        for r in range(len(s)):
            c = s[r]
            countS[c] += 1
            if countS[c] == countT[c]:
                have += 1
            while have == need:
                if r - l + 1 < minLen: 
                    minstr = s[l:r+1]
                    minLen = r-l+1
                countS[s[l]] -= 1
                if s[l] in countT and countS[s[l]] < countT[s[l]]:
                    have -= 1
                l +=1
        return minstr if minLen != float("infinity") else ""


                