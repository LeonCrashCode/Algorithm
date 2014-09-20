#ifndef RemoveDuplicatesfromSortedListII_H
#define RemoveDuplicatesfromSortedListII_H

#include "common.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *pre = &dummy;
        ListNode *p = head;
        ListNode *q = p->next;
        
        bool flag = false;
        while(q)
        {
            if(p->val == q->val)
            {
                flag = true;
                p->next = q->next;
                q = p->next;
            }
            else
            {
                if(flag == false)
                {
                    pre = pre->next;
                    p = p->next;
                    q = q->next;
                }
                else
                {
                    flag = false;
                    pre->next = p->next;
                    p = pre->next;
                    if(p)
                        q = p->next;
                    else
                        q = NULL;
                }
            }
        }
        if(flag)
        {
            pre->next = p->next;
        }
        return dummy.next;
    }
};

#endif