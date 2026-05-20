class Solution {
public:
  string multiply(string num1, string num2) {
    int n = num1.size();
    int m = num2.size();
    vector<int> res(n + m);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        int digit = (num1[i] - '0') * (num2[j] - '0');
        res[i + j + 1] += digit;
        res[i + j] += res[i + j + 1] / 10;
        res[i + j + 1] = res[i + j + 1] % 10;
      }
    }
    int i = 0;
    while (i < res.size() && res[i] == 0) {
      i++;
    }
    string t = "";
    for (; i < res.size(); i++) {
      t += to_string(res[i]);
    }

    return t.empty() ? "0" : t;
  }




};
