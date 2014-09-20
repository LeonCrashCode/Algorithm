#ifndef SameTree_H
#define SameTree_H

#include "common.h"
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        bool flag = true;
        dfs(p,q,flag);
        return flag;
        
    }
private:
    void dfs(TreeNode *p, TreeNode *q, bool &flag) {
        if(flag == false) return;
        
        if(p == NULL) {
            if(q != NULL) flag = false;
            return ;
        }
        if(q == NULL) {
            if(p != NULL) flag = false;
            return;
        }
        if(p->val != q->val)
        {
            flag = false;
            return;
        }
        dfs(p->left,q->left,flag);
        dfs(p->right,q->right,flag);
    }
};

#endif