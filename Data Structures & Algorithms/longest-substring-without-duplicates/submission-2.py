class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        l, r = 0, 0
        chars = set()
        maxL = 0
        while r < len(s):
            if s[r] not in chars:
                chars.add(s[r])
                maxL = max(maxL, (r-l+1))
                r += 1
            elif chars:
                chars.remove(s[l])
                l += 1
        return maxL