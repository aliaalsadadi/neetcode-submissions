class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        w = []
        word = list(word)
        path = set()
        def traverse(i,j,k):
            if k == len(word):
                return True
            if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]) or (i,j) in path:
                return False
            if word[k] != board[i][j]:
                return False
            path.add((i,j))
            res = (traverse(i+1,j,k+1) or 
            traverse(i,j+1,k+1) or
            traverse(i-1,j,k+1) or 
            traverse(i,j-1,k+1)
            )
            path.remove((i,j))
            return res
        for i in range(len(board)):
            for j in range(len(board[0])):
                if traverse(i,j,0):
                    return True
        return False