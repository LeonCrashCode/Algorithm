#ifndef PopulatingNextRightPointersinEachNodeII_H
#define PopulatingNextRightPointersinEachNodeII_H

#include "common.h"
#include <queue>

using namespace std;

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if(root == NULL) return;
		if(root->left == NULL && root->right == NULL) return;

		queue<pair<TreeLinkNode*, int>> q;
		if(root->left!=NULL)
		q.push(make_pair(root->left,1));
		if(root->right!=NULL)
		q.push(make_pair(root->right,1));
		pair<TreeLinkNode*,int> top = make_pair(root,0);
		while(q.empty()==false)
		{
			if(top.second != q.front().second)
			{
				top.first->next = NULL;
			}
			else
			{
				top.first->next = q.front().first;
			}
			top = q.front();
			q.pop();

			if(top.first->left != NULL) q.push(make_pair(top.first->left,top.second+1));
			if(top.first->right != NULL) q.push(make_pair(top.first->right,top.second+1));
		}
	}
};
#endif