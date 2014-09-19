#ifndef ConstructBinaryTreefromInorderandPostorderTraversal_H
#define ConstructBinaryTreefromInorderandPostorderTraversal_H

#include "common.h"
#include <vector>
using namespace std;
class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
	}
private:
	TreeNode *buildTree(vector<int> &inorder,int in_start,int in_end, vector<int> &postorder, int post_start, int post_end) {
		if(in_start > in_end) return NULL;
		if(post_start > post_end) return NULL;

		TreeNode *head = new TreeNode(postorder[post_end]);
		int head_inpos = find(inorder, in_start, postorder[post_end]);
		int left_length = head_inpos - in_start;
		head->left = buildTree(inorder,in_start,head_inpos-1,postorder,post_start,post_start+left_length-1);
		head->right = buildTree(inorder,head_inpos+1,in_end,postorder,post_start+left_length,post_end-1);
		return head;
	}
	int find(vector<int> &inorder, int start, int head_value) {
		for(int i = start; i < inorder.size(); i ++) {
			if(inorder[i] == head_value) return i;
		}
		return -1;
	}
};
#endif