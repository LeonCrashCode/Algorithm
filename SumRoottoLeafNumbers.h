#ifndef SumRoottoLeafNumbers_H
#define SumRoottoLeafNumbers_H

#include "common.h"

class Solution {
public:
	int dfs(TreeNode *root,int value)
	{
		if(root->left == NULL && root->right == NULL)
			return value+root->val;
		int now = 0;
		if(root->left !=NULL)
			now += dfs(root->left,(value+(root->val))*10);
		if(root->right != NULL)
			now += dfs(root->right,(value+(root->val))*10);
		return now;
	}
	int sumNumbers(TreeNode *root) {
		if(root == NULL) return 0;
		return dfs(root,0);
	}
};
#endif