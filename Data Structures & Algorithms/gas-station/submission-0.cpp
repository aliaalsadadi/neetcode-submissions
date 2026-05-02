class Solution {
public:
      int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    for (int i = 0; i < gas.size(); i++) {
      int total = 0;
      for (int j = i; j < n + i; j++) {
        total += gas[j % n];
        total -= cost[j % n];
        if (total < 0) {
          break;
        }
      }
      if (total >= 0) {
        return i;
      }
    }
    return -1;
  }


};
