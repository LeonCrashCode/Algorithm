#ifndef MergekSortedLists_H
#define MergekSortedLists_H

#include "common.h"
#include <queue>
using namespace std;


class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if(lists.size() == 0) return NULL;

		int increment = 1;
		queue<ListNode *>Q;
		for(int i = 0; i < lists.size(); i ++)
		{
			Q.push(lists[i]);
		}
		while(Q.size()!=1)
		{
			ListNode *one = Q.front();
			Q.pop();
			ListNode *two = Q.front();
			Q.pop();
			Q.push(merge(one,two));
		}
		return Q.front();
	}
private:
	ListNode* merge(ListNode *one, ListNode* two)
	{
		ListNode dummy(-1);
		ListNode *p = &dummy;

		while(one!=NULL && two!=NULL)
		{
			if(one->val<=two->val)
			{
				p->next = one;
				one = one->next;
			}
			else
			{
				p->next = two;
				two = two->next;
			}
			p = p->next;
		}

		while(one!=NULL)
		{
			p->next = one;
			p = p->next;
			one = one->next;
		}
		while(two!=NULL)
		{
			p->next = two;
			p = p->next;
			two = two->next;
		}
		return dummy.next;
	}
};

#endif