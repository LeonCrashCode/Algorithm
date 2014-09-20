#ifndef PathSum_H
#define PathSum_H

#include "common.h"

class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		if(root == NULL) return false;

		bool flag = false;
		dfs(root,sum,flag);
		return flag;
	}
private:
	void dfs(TreeNode *root, int sum, bool &flag) {
		if(flag) return;
		if(root ->left == NULL && root->right == NULL)
		{
			if(sum - root->val == 0)
			{
				flag = true;
			}
			return;
		}
		if(root->left != NULL)
			dfs(root->left, sum-(root->val), flag);
		if(root->right != NULL)
			dfs(root->right, sum-(root->val), flag);
	}
};

#endif