class Solution {
public:
       int reverse(int x) {
    int i = 0;
    int res = 0;
    bool isNeg = x < 0;
    if (isNeg)
      x *= -1;
    while (x > 0) {
        int digit = x % 10;
            x /= 10;

        if (res > INT_MAX / 10) {
            return 0;
        }
        if (res < INT_MIN / 10) {
            return 0;
        }
      res *= 10;
      res += digit;
    }
    if (isNeg)
      res *= -1;

    return res;
  }


};
