#ifndef BinaryTreeMaximumPathSum_H
#define BinaryTreeMaximumPathSum_H

#include "common.h"
class Solution {
public:
	int maxPathSum(TreeNode *root) {
		int max_sum = -10000000;
		int t = dfs(root,max_sum);
		return max_sum;
	}
private:
	int dfs(TreeNode *root,int &max_sum) {
		if(root == NULL) return 0;
		int l = dfs(root->left,max_sum);
		int r = dfs(root->right,max_sum);
		int sum = root->val;
		if(l>0) sum +=l;
		if(r>0) sum +=r;
		max_sum = max(max_sum,sum);
		if(max(l,r)>0) return root->val+max(l,r);
		else return root->val;
	}
};
#endif