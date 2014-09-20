#ifndef RemoveDuplicatesfromSortedList_H
#define RemoveDuplicatesfromSortedList_H

#include "common.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *p = head;
        ListNode *q = p->next;
        while(q)
        {
            if(p->val == q->val)
            {
                p->next = q->next;
                q = p->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};

#endif