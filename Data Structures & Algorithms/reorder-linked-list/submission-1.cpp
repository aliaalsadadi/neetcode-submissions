/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  void reorderList(ListNode *head) {
    vector<int> list;
    ListNode *cur = head;
    while (cur != nullptr) {
      list.push_back(cur->val);
      cur = cur->next;
    }
    int n = list.size();
    cur = head;
    int l = 0;
    int r = n - 1;
    for (int i = 0; cur != nullptr; i++) {
      if (i % 2 == 0) {
        cur->val = list[l];
        l++;
      } else {
        cur->val = list[r];
        r--;
      }
      cur = cur->next;
    }
  }



};
