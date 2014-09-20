#ifndef ValidateBinarySearchTree_H
#define ValidateBinarySearchTree_H

#include "common.h"

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode *p = root;
        TreeNode *prev = NULL;
        while(p!=NULL) {
            if(p->left == NULL) {
                if(detect(prev,p)==false) return false;
                prev = p;
                p = p->right;
            }
            else
            {
                TreeNode *tmp = p->left;
                while(tmp->right!=NULL&&tmp->right!=p) tmp = tmp->right;
                if(tmp->right == NULL) {
                    tmp->right = p;
                    p = p->left;
                }
                else
                {
                    if(detect(prev,p)==false)return false;
                    tmp->right = NULL;
                    prev = p;
                    p = p->right;
                }
            }
            
        }
        return true;
    }
private:
    bool detect(TreeNode *prev, TreeNode *p) {
        if(prev != NULL && p != NULL && prev->val > p->val) return false;
        return true;
    }
};

#endif