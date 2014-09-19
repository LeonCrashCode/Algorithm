#ifndef ReverseNodesinkGroup_H
#define ReverseNodesinkGroup_H

#include "common.h"

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if(k == 1) return head;
		if(head == NULL || head->next == NULL) return head;

		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p = &dummy;
		while(p!=NULL && p->next !=NULL &&p->next->next!=NULL)
		{
			ListNode *q,*r;
			q = p->next;
			r = q->next;

			ListNode *t = p;
			int cnt = 0;
			while(t!=NULL)
			{
				cnt +=1;
				t = t->next;
				if(cnt == k) break;
			}
			if(t == NULL) break;


			for(int i = 0; i < k-1; i ++)
			{
				if(r == NULL) break;

				q->next = r->next;
				r->next = p->next;
				p->next = r;

				r = q->next;
			}
			p = q;
		}
		return dummy.next;
	}
};

#endif