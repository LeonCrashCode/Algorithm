#ifndef ReverseLinkedListII_H
#define ReverseLinkedListII_H

#include "common.h"
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n) return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *prev = &dummy;
        for(int i = 0; i < m-1; i ++)
        {
            prev = prev->next;
        }
        ListNode *h = prev;
        prev = prev->next;
        ListNode *cur = prev->next;
        for(int i = m; i < n; i ++)
        {
            prev->next = cur->next;
            cur->next = h->next;
            h->next = cur;
            cur = prev->next;
        }
        return dummy.next;
    }
};

#endif