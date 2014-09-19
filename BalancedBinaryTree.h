#ifndef BalancedBinaryTree_H
#define BalancedBinaryTree_H

#include "common.h"

class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if(root == NULL) return true;

		bool flag = true;
		dfs(root,flag);
		return flag;

	}
private:
	int dfs(TreeNode *root, bool &flag) {
		if(flag == false) return 0;
		if(root->left == NULL && root->right == NULL)
		{
			return 1;
		}

		int l=0;
		int r=0;
		if(root->left != NULL)
			l = dfs(root->left,flag);
		if(root->right != NULL)
			r = dfs(root->right,flag);
		if(max(l,r)-min(l,r)>1) flag = false;

		return max(l,r)+1;
	}
};
#endif