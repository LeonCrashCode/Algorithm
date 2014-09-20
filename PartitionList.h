#ifndef PartitionList_H
#define PartitionList_H

#include "common.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL) return head;
        
        ListNode dummy1(0);
        ListNode dummy2(0);
        
        ListNode *less = &dummy1;
        ListNode *greater = &dummy2;
        
        ListNode *p = head;
        while(p!=NULL)
        {
            if(p->val<x)
            {
                less->next = p;
                less = less->next;
            }
            else
            {
                greater->next = p;
                greater = greater->next;
            }
            p = p->next;
        }
        greater->next = NULL;
        less->next = dummy2.next;
        return dummy1.next;
    }
};

#endif