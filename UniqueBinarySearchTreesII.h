#ifndef UniqueBinarySearchTreesII_H
#define UniqueBinarySearchTreesII_H

#include "common.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1,n);
    }
private:
    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> tree;
        if(start> end)
        {
            tree.push_back(NULL);
            return tree;
        }
        for(int k = start; k <= end; k ++) {
            vector<TreeNode *> lv = generateTrees(start,k-1);
            vector<TreeNode *> rv = generateTrees(k+1,end);
            for(int i = 0; i < lv.size(); i ++)
            {
                for(int j = 0; j < rv.size(); j ++)
                {
                    TreeNode *root = new TreeNode(k);
                    root->left = lv[i];
                    root->right = rv[j];
                    tree.push_back(root);
                }
            }
        }
        return tree;
    }
};

#endif