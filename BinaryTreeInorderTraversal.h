#ifndef BinaryTreeInorderTraversal_H
#define BinaryTreeInorderTraversal_H

#include "common.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *p = root;
        while(p)
        {
            if(p->left ==NULL)
            {
                result.push_back(p->val);
                p = p->right;
            }
            else
            {
                TreeNode *tmp = p->left;
                while(tmp->right!=NULL && tmp->right !=p) tmp = tmp->right;
                if(tmp->right == NULL) {
                    tmp->right = p;
                    p = p->left;
                }
                else
                {
                    result.push_back(p->val);
                    tmp->right = NULL;
                    p = p->right;
                }
                
            }
        }
        return result;
    }
};

#endif