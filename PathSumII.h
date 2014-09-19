#ifndef PathSumII_H
#define PathSumII_H

#include "common.h"

class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int>> result;
		if(root == NULL) return result;

		vector<int> path;
		dfs(root,sum,result,path);
		return result;
	}
private:
	void dfs(TreeNode *root, int sum, vector<vector<int>> &result, vector<int> &path) {
		if(root ->left == NULL && root->right == NULL)
		{
			if(sum - root->val == 0)
			{
				path.push_back(root->val);
				result.push_back(path);
				path.pop_back();
			}
			return;
		}
		if(root->left != NULL)
		{
			path.push_back(root->val);
			dfs(root->left, sum-(root->val), result,path);
			path.pop_back();
		}
		if(root->right != NULL)
		{
			path.push_back(root->val);
			dfs(root->right, sum-(root->val), result,path);
			path.pop_back();
		}
	}
};

#endif