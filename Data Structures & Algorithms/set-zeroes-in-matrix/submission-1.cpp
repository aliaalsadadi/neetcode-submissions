class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    bool rowZero = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          if (i > 0) {
            matrix[i][0] = 0;
          } else {
            rowZero = true;
          }
        }
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
     if (matrix[0][0] == 0) {
            for (int r = 0; r < n; r++) {
                matrix[r][0] = 0;
            }
        }
    if (rowZero) {
      for (int j = 0; j < m; j++) {
        matrix[0][j] = 0;
      }
    }
  }



};
