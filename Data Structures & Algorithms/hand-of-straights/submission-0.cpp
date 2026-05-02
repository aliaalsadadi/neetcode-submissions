class Solution {
public:
       bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0)
      return false;

    unordered_map<int, int> countM;
    for (int i = 0; i < hand.size(); i++) {
      countM[hand[i]]++;
    }
    sort(hand.begin(), hand.end());
    for (int i = 0; i < hand.size(); i++) {
      if (countM[hand[i]] > 0) {
        for (int j = 0; j < groupSize; j++) {
          if (countM[hand[i] + j] == 0) {
            return false;
          }
          countM[hand[i] + j]--;
        }
      }
    }
    return true;
  }


};
