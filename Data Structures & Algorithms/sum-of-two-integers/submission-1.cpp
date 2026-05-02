class Solution {
public:
    int getSum(int a, int b) {
        int ab = a ^ b;
        int carry = (a & b ) << 1;
        while (carry != 0) {
            int newCarry = (ab & carry) << 1;
            ab = ab^carry;
            carry = newCarry;
        }
        return ab;
    }
};
