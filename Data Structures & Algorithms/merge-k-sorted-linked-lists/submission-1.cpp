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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* res = new ListNode(-1);
    ListNode* cur = res;
    while (true) {
      int minNode = INT_MAX;
      int minIdx = -1;
      for (int i = 0; i < lists.size(); i++) {
        if (!lists[i])
          continue;
        if (lists[i]->val < minNode) {
          minIdx = i;
          minNode = lists[i]->val;
        }
      }
      if (minIdx == -1)
        break;
      lists[minIdx] = lists[minIdx]->next;
      cur->next = new ListNode(minNode);
      cur = cur->next;
    }
    return res->next;
  }




};
