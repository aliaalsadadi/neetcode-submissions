class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)
        print(n)
        #check column duplicates
        squares = defaultdict(set)
        for i in range(n):
            col = set()
            row = set()
            for j in range(n):
                if board[i][j] != ".":
                    if board[i][j] in row or board[i][j] in squares[(i // 3, j // 3)]:
                        return False
                    row.add(board[i][j])
                    squares[(i // 3, j // 3)].add(board[i][j])
                if board[j][i] != ".":
                    if board[j][i] in col:
                        return False
                    col.add(board[j][i])
        return True