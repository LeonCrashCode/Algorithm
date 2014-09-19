#ifndef MergeTwoSortedLists_H
#define MergeTwoSortedLists_H

#include "common.h"
using namespace std;
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1==NULL && l2 == NULL) return NULL;
		if(l1==NULL) return l2;
		if(l2==NULL) return l1;

		ListNode *p1 = l1;
		ListNode *p2 = l2;

		ListNode dummy(-1);
		ListNode *cur = &dummy;
		while(p1!=NULL && p2!=NULL)
		{
			if(p1->val < p2->val) 
			{
				cur->next = p1;
				p1 = p1->next;
			}
			else
			{
				cur->next = p2;
				p2 = p2->next;
			}
			cur = cur->next;
		}
		while(p1!=NULL){cur->next = p1;p1 = p1->next;cur = cur->next;}
		while(p2!=NULL){cur->next = p2;p2 = p2->next;cur = cur->next;}
		cur->next = NULL;
		return dummy.next;
	}
};

#endif
