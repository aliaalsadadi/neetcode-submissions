class Solution {
public:
        bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> rowSet(9);
        unordered_set<char> columnSet(9);
        unordered_map<int, unordered_set<char>> square;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.' ) {
                    if (rowSet.contains(board[i][j]))
                    {
                        return false;
                    }
                    int row = (i / 3);
                    int col = (j / 3);
                    if (square[row * 3 + col].contains(board[i][j]))
                    {
                        return false;
                    }
                    square[row * 3 + col].insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (columnSet.contains(board[j][i]))
                    {
                        return false;
                    }
                }
                
                rowSet.insert(board[i][j]);
                columnSet.insert(board[j][i]);
            }
            rowSet.clear();
            columnSet.clear();
        }
        return true;
    };


};
