class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t.lstrip('-').isdigit():  # Handle negative numbers
                stack.append(int(t))
            else:
                num1 = stack.pop()
                num2 = stack.pop()
                if t  == "+":
                    stack.append(num1+num2)
                elif t == "-":
                    stack.append(num2 - num1)
                elif t == "*":
                    stack.append(num2*num1)
                else:
                    stack.append(int(num2/num1))
        return stack[0]