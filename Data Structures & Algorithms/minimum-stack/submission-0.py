class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        if isinstance(val,int):
            self.stack.append(val)

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[len(self.stack)-1]

    def getMin(self) -> int:
        n = self.stack[0]
        for i in range(len(self.stack)):
            n = min(self.stack[i],n)
        return n
