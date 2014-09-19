#ifndef BinaryTreePreorderTraversal_H
#define BinaryTreePreorderTraversal_H

#include "common.h"
#include <vector>
using namespace std;

class  Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> vv;
		if(root == NULL)
			return vv;

		
		vv.push_back(root->val);
		vector<int> vl = preorderTraversal(root->left);
		vector<int> vr = preorderTraversal(root->right);

		vv.insert(vv.end(),vl.begin(),vl.end());
		vv.insert(vv.end(),vr.begin(),vr.end());

		return vv;
	}
};
#endif