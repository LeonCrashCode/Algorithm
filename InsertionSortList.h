#ifndef INSERTIONSORTLIST_H
#define INSERTIONSORTLIST_H

#include "common.h"

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if(head == NULL) return NULL;
		if(head->next == NULL) return head;

		ListNode *H = new ListNode(0);
		H->next = head;
		ListNode *np = head->next;
		head->next = NULL;
		while(np!=NULL)
		{
			ListNode *p = H;
			while(p->next!=NULL)
			{
				if((p->next)->val > np->val)
				{
					ListNode *tmp = np->next;
					np->next = p->next;
					p->next = np;
					np = tmp;
					break;
				}
				p = p->next;
			}
			if(p->next == NULL)
			{
				p->next = np;
				np = np->next;

				(p->next)->next = NULL; //pay more attion to this point:  it can form a cycle without NULL
			}
		}
		return H->next;

	}
};

#endif