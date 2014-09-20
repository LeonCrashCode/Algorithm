#ifndef BinaryTreeLevelOrderTraversalII_H
#define BinaryTreeLevelOrderTraversalII_H

#include "common.h"
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int>> result;
		if(root == NULL) return result;

		queue<pair<TreeNode*, int>> q;

		pair<TreeNode*, int> top = make_pair(root,0);
		if(root->left != NULL)
			q.push(make_pair(root->left,1));
		if(root->right != NULL)
			q.push(make_pair(root->right,1));

		vector<int> path;
		path.push_back(root->val);

		while(q.empty()==false)
		{
			if(top.second != q.front().second)
			{
				result.push_back(path);
				path.clear();
			}
			top = q.front();
			q.pop();

			path.push_back(top.first->val);
			if(top.first->left !=NULL) q.push(make_pair(top.first->left,top.second+1));
			if(top.first->right !=NULL) q.push(make_pair(top.first->right,top.second+1));
		}
		if(path.size()!=0) result.push_back(path);
		reverse(result.begin(),result.end());
		return result;
	}
};
#endif