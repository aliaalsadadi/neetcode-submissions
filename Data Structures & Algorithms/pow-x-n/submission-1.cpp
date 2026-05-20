class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) return 1.0;
    double res = x;
    bool isNeg = n < 0;
    if (isNeg) {
      n *= -1;
      res = 1;
    }

    if (isNeg) {
      for (int i = 0; i < n; i++) {
        res /= x;
      }
    } else {
      for (int i = 1; i < n; i++) {
        res *= x;
      }
    }
    return res;
  }

};
