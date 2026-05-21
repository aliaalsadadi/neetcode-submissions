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
    if (lists.size() == 0)
      return nullptr;
    for (int i = 1; i < lists.size(); i++) {
      lists[i] = mergeLists(lists[i], lists[i - 1]);
    }
    return lists[lists.size() - 1];
  }
  ListNode* mergeLists(ListNode* list1, ListNode* list2) {
    ListNode* res = new ListNode(-1);
    ListNode* dummy = res;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        dummy->next = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        dummy->next = new ListNode(list2->val);
        list2 = list2->next;
      }
      dummy = dummy->next;
    }
    if (list1 != nullptr) {
      dummy->next = list1;
    }
    if (list2 != nullptr) {
      dummy->next = list2;
    }
    return res->next;
  }


};
