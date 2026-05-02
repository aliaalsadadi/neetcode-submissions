class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        brack_map = {   
            '(': ')',
            '[': ']',
            '{': '}',
        }
        for i in range(len(s)):
            if s[i] in brack_map:
                stack.append(brack_map[s[i]])
            elif len(stack) == 0 or s[i] != stack.pop():
                return False
        return len(stack) == 0    


