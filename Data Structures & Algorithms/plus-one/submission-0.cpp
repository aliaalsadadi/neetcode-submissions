class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        int carry = 1;
        while (i >= 0) {
            int d = digits[i];
            int temp = d + carry;
            if (temp > 9 ) {
                carry = temp / 10;
                digits[i] = temp % 10;
            } else {
                digits[i] = temp;
                carry = 0;
            }
            i--;
        }
        if (carry != 0) {
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
