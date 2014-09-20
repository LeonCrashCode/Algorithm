#ifndef BinaryTreeZigzagLevelOrderTraversal_H
#define BinaryTreeZigzagLevelOrderTraversal_H

#include "common.h"
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
        for(int i = 0; i < result.size(); i ++)
        {
            if(i%2 == 1) reverse(result[i].begin(),result[i].end());
        }
        return result;
    }
};

#endif