class Solution {
public:
    double myPow(double x, int n) {
    if (x == 0)
      return 0;
    if (n == 0)
      return 1;
    if (n == 1) {
      return x;
    }
    double res = myPow(x, abs(n / 2));
    if (n % 2 == 0) {
      res = res * res;
    } else {
      res = res * res * x;
    }
    return (n >= 0) ? res : 1 / res;
  }


};
