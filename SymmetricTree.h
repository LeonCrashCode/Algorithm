#ifndef SymmetricTree_H
#define SymmetricTree_H


#include "common.h"
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        vector<vector<int>> result;
        if(root == NULL) return true;
        
        queue<pair<TreeNode*, int>> q;
        
        pair<TreeNode*, int> top = make_pair(root,0);
        if(root->left != NULL)
            q.push(make_pair(root->left,1));
        else q.push(make_pair(new TreeNode(-100000),1));
        if(root->right != NULL)
            q.push(make_pair(root->right,1));
        else q.push(make_pair(new TreeNode(-100000),1));
        
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
            
            if(top.first->val == -100000) path.push_back(-100000);
            else
            {
                path.push_back(top.first->val);
                if(top.first->left !=NULL) q.push(make_pair(top.first->left,top.second+1));
                else q.push(make_pair(new TreeNode(-100000),top.second+1));
                if(top.first->right !=NULL) q.push(make_pair(top.first->right,top.second+1));
                else q.push(make_pair(new TreeNode(-100000),top.second+1));
            }
        }
        if(path.size()!=0) result.push_back(path);
        
        for(int i = 0 ; i < result.size(); i ++)
        {
            if(isSymmetric(result[i])==false) return false;
        }
        return true;
    }
private:
    bool isSymmetric(vector<int> &path) {
        int i = 0;
        int j = path.size()-1;
        while(i<=j)
        {
            if(path[i]!=path[j])
                return false;
            i += 1;
            j -= 1;
        }
        return true;
    }
};

#endif