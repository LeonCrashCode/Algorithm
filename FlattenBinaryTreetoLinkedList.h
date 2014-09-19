#ifndef FlattenBinaryTreetoLinkedList_H
#define FlattenBinaryTreetoLinkedList_H
#include "common.h"

class Solution {
public:
	void flatten(TreeNode *root) {
		preorder(root,NULL);
	}
private:
	TreeNode* preorder(TreeNode *root, TreeNode *tail) {
		if(root == NULL) return tail;

		root->right = preorder(root->left,preorder(root->right,tail));
		root->left = NULL;
		return root;
	}
};
#endif