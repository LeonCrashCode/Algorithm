#ifndef RemoveNthNodeFromEndofList_H
#define RemoveNthNodeFromEndofList_H

#include "common.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
            return NULL;
        //ListNode dummyHead(0); 
        
        ListNode *h2 = head;
        int len = 0;
        while(!h2)
        {
            len++;
            h2 = h2->next;
        }
        int i = 0;
        ListNode h(0); 
        h.next = head;
        ListNode *p = &h;
        while(i < len - n)
        {
            p = p->next;
            i++;
        }
        
        p->next = p->next->next;
        return h.next;
    }
};
#endif