class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head)
      return head;
    ListNode* prev = nullptr;
    while (head) {
      ListNode* tmp = head->next;
      head->next = prev;
      prev = head;
      head = tmp;
    }
    
    return prev;
  }
};
