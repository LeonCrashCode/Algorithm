#ifndef ReorderList_H
#define ReorderList_H

#include "common.h"
class Solution {
public:
	ListNode *getmiddle(ListNode *head) {
		ListNode *p1 = head;
		ListNode *p2 = head->next;
		while(p2!=NULL && p2->next!=NULL)
		{
			p1 = p1->next;
			p2 = (p2->next)->next;
		}
		return p1;
	}
	ListNode *reverse(ListNode *head) {
		if(head == NULL) return NULL;
		if(head->next == NULL) return head;

		ListNode *p = head;
		ListNode *q = head->next;
		ListNode *r;
		p->next = NULL;
		while(q!=NULL)
		{
			r = q->next;
			q->next = p;

			p = q;
			q = r;
		}
		return p;
	}
	ListNode *merge(ListNode *left, ListNode *right) {
		ListNode *head = left;
		ListNode *pl = left->next;
		ListNode *pr = right;

		bool flag = true;
		while(pl!=NULL && pr!=NULL)
		{
			if(flag)
			{
				left->next = pr;
				pr = pr->next;
				left = left->next;
				flag = false;
			}
			else
			{
				left->next = pl;
				pl = pl->next;
				left = left->next;
				flag = true;
			}
		}
		while(pl!=NULL)
		{
			left->next = pl;
			pl = pl->next;
			left = left->next;
		}
		while(pr!=NULL)
		{
			left->next = pr;
			pr = pr->next;
			left = left->next;
		}
		return head;
	}
	void reorderList(ListNode *head) {
		if(head == NULL) return ;
		if(head->next == NULL) return ;
		if((head->next)->next == NULL) return ;

		ListNode *mid = getmiddle(head);
		ListNode *right = mid->next;
		mid->next = NULL;
		head = merge(head,reverse(right));
	}
};
#endif
