#ifndef SwapNodesinPairs_H
#define SwapNodesinPairs_H

#include "common.h"

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if(head == NULL || head->next == NULL) return head;

		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p = &dummy;
		while(p!=NULL && p->next !=NULL &&p->next->next!=NULL)
		{
			ListNode *q,*r;
			q = p->next;
			r = q->next;


			q->next = r->next;
			r->next = p->next;
			p->next = r;

			r = q->next;
			p = q;
		}
		return dummy.next;
	}
};

#endif