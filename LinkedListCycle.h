#ifndef LinkedListCycle_H
#define LinkedListCycle_H

#include "common.h"
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if(head == NULL) return NULL;
		ListNode *p1 = head;
		ListNode *p2 = head;
		bool flag = false;
		while(p2!=NULL && p2->next!=NULL)
		{
			p1 = p1->next;
			p2 = (p2->next)->next;
			if(p1 == p2)
			{
				flag = true;
				break;
			}
		}
		if(flag == false) return NULL;

		p1 = head;
		if(p1==p2) return head;
		while(true)
		{
			p1 = p1->next;
			p2 = p2->next;
			if(p1 == p2) return p1;
		}
		return NULL;
	}
};
#endif
