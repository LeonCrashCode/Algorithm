#ifndef ConvertSortedArraytoBinarySearchTree_H
#define ConvertSortedArraytoBinarySearchTree_H

#include "common.h"

class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return two_divided(num, 0,num.size()-1);
	}
private:
	TreeNode *two_divided(vector<int> &num, int start, int end) {
		if(start > end) return NULL;

		int mid = (start+end)/2;
		TreeNode *head = new TreeNode(num[mid]);
		head->left = two_divided(num,start,mid-1);
		head->right = two_divided(num,mid+1,end);
		return head;
	}
};
#endif