#ifndef MaximumDepthofBinaryTree_H
#define MaximumDepthofBinaryTree_H

#include "common.h"
#include <queue>
using namespace std;

class Solution {
public:
	int maxDepth(TreeNode *root) {
		if(root == NULL) return 0;
		queue<pair<TreeNode *,int>> q;
		q.push(make_pair(root,1));
		int MaxDepth = -1;
		while(q.empty()==false)
		{
			pair<TreeNode *,int> top = q.front();
			q.pop();
			MaxDepth = max(MaxDepth,top.second);
			if(top.first->left != NULL)
				q.push(make_pair(top.first->left,top.second+1));
			if(top.first->right != NULL)
				q.push(make_pair(top.first->right,top.second+1));
		}
		return MaxDepth;
	}
};
#endif