#ifndef RecoverBinarySearchTree_H
#define RecoverBinarySearchTree_H

#include "common.h"
using namespace std;

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *p = root;
        TreeNode *prev = NULL;
        pair<TreeNode *,TreeNode *> result;
        while(p!=NULL)
        {
            if(p->left == NULL)
            {
                detect(result,prev,p);
                prev = p;
                p = p->right;
            }
            else
            {
                TreeNode *tmp = p->left;
                while(tmp->right != NULL && tmp->right !=p) tmp = tmp->right;
                if(tmp->right == NULL)
                {
                    tmp->right = p;
                    p = p->left;
                }
                else
                {
                    detect(result,prev,p);
                    tmp->right = NULL;
                    prev = p;
                    p = p->right;
                }
            }
        }
        swap(result.first->val,result.second->val);
    }
private:
    void detect(pair<TreeNode *,TreeNode *> &result, TreeNode *prev, TreeNode *p) {
        if(prev!=NULL && prev->val > p->val) {
            if(result.first == NULL)
                result.first = prev;
            result.second = p;
        }
    }
};

#endif