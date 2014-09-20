#ifndef SORTLIST_H
#define SORTLIST_H

#include "common.h"
 //merge sort
class Solution {
public:
    ListNode *getmiddle(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while(p2 !=NULL && p2->next != NULL)
        {
            p1 = p1->next;
            p2 = (p2->next)->next;
        }
        return p1;
    }
    ListNode *sortList(ListNode *head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        ListNode *mid = getmiddle(head);
        ListNode *left = mid->next;
        mid->next = NULL;
        return merge(sortList(head),sortList(left));
    }
    ListNode *merge(ListNode *right, ListNode *left) {
        ListNode *H = new ListNode(0);
        ListNode *p = H;
        ListNode *pr = right;
        ListNode *pl = left;
        while(pr!=NULL && pl!=NULL)
        {
            if(pr->val<pl->val)
            {
                p->next = pr;
                pr = pr->next;
            }
            else
            {
                p->next = pl;
                pl = pl->next;
            }
            p = p->next;
        }
        while(pr!=NULL)
        {
            p->next = pr;
            pr = pr->next;
            p = p->next;
        }
        while(pl!=NULL)
        {
            p->next = pl;
            pl = pl->next;
            p = p->next;
        }
        return H->next;
    }
};

#endif 