#ifndef Combinations_H
#define Combinations_H

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        
        dfs(n,1,0,k,path,result);
        return result;
    }
private:
    void dfs(const int &n, int start, int step, const int &k, vector<int> &path, vector<vector<int>> &result) {
        if(step == k)
        {
            result.push_back(path);
            return;
        }
        for(int i = start; i <= n; i ++)
        {
            path.push_back(i);
            dfs(n,i+1,step+1,k,path,result);
            path.pop_back();
        }
    }
};

#endif