class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head)
      return head;
    ListNode* prev = nullptr;
    while (head->next) {
      ListNode* tmp = head->next;
      head->next = prev;
      prev = head;
      if (tmp)
        head = tmp;
      else
        break;
    }
    head->next = prev;
    
    return head;
  }
};
