#ifndef BinaryTreePostorderTraversal_H
#define BinaryTreePostorderTraversal_H

#include "common.h"
#include <vector>
using namespace std;

class  Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> vv;
		if(root == NULL)
			return vv;

		vector<int> vl = postorderTraversal(root->left);
		vector<int> vr = postorderTraversal(root->right);

		vv.insert(vv.end(),vl.begin(),vl.end());
		vv.insert(vv.end(),vr.begin(),vr.end());
		vv.push_back(root->val);

		return vv;
	}
};
#endif