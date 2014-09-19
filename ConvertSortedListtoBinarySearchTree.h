#ifndef ConvertSortedListtoBinarySearchTree_H
#define ConvertSortedListtoBinarySearchTree_H

#include "common.h"

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		return two_divided(head);
	}
private:
	TreeNode *two_divided(ListNode *start) {
		if(start == NULL) return NULL;
		TreeNode *head = NULL;
		if(start->next == NULL)
		{
			head = new TreeNode(start->val);
			return head;
		}
		if(start->next->next == NULL)
		{
			head = new TreeNode(start->next->val);
			start->next = NULL;
			head->left = two_divided(start);
			return head;
		}
		ListNode *p,*q,*s;
		p = start;
		q = start->next;
		s = start->next->next;
		while(s && s->next)
		{
			p = p->next;
			q = q->next;
			s = s->next->next;
		}
		head = new TreeNode(q->val);
		p->next = NULL;
		head->left = two_divided(start);
		head->right = two_divided(q->next);
		return head;
	}

};
#endif