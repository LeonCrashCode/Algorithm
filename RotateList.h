#ifndef RotateList_H
#define RotateList_H

#include "common.h"

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if(head == NULL) return head;
		if(head->next == NULL) return head;
		ListNode *p = head;
		ListNode *q = head;
		for(int i = 0; i < k; i ++) {
			p = p->next;
			if(p == NULL) p = head;
		}
		while(p->next!=NULL)
		{
			p = p->next;
			q = q->next;
		}
		p->next = head;
		ListNode *tmp = q;
		q = q->next;
		tmp->next = NULL;
		return q;
	}
};

#endif