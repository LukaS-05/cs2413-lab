// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      struct ListNode* pre = head;
      struct ListNode* cur = head;
      struct ListNode* temp = NULL;
      struct ListNode* newHead = (head == NULL ? head : (head->next == NULL ? head : head->next));
      while (pre != NULL)
      {
            pre = cur;
            cur = (cur == NULL ? cur : cur->next);
            // 1,2,3,4
            if (cur != NULL)
            {
                  temp = cur->next;
                  cur->next = pre;
                  pre->next = temp;
            }
            else
            {
                  break;
            }

            cur = temp;
      }
      return newHead;
}