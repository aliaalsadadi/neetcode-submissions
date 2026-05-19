class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> res(n * m);
    const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
    int i = 0, j = 0;
    int dir = RIGHT;
    int c = 0;
    int RIGHT_WALL = m, LEFT_WALL = 0, DOWN_WALL = n, UP_WALL = 0;
    while (c != res.size()) {
      switch (dir) {
      case RIGHT:
        for (; j < RIGHT_WALL; j++) {
          res[c] = matrix[i][j];
          c++;
        }
        RIGHT_WALL--;
        j--;
        i++;
        dir = DOWN;
        break;

      case DOWN:
        for (; i < DOWN_WALL; i++) {
          res[c] = matrix[i][j];
          c++;
        }
        DOWN_WALL--;
        i--;
        j--;
        dir = LEFT;
        break;
      case LEFT:
        for (; j >= LEFT_WALL; j--) {
          res[c] = matrix[i][j];
          c++;
        }
        LEFT_WALL++;
        j++;
        i--;
        dir = UP;
        break;
      case UP:
        for (; i > UP_WALL; i--) {
          res[c] = matrix[i][j];
          c++;
        }
        UP_WALL++;
        i++;
        j++;
        dir = RIGHT;
        break;
      }
    }

    return res;
  }







};