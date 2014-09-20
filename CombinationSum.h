#ifndef CombinationSum_H
#define CombinationSum_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> one;
        if(candidates.size() == 0)
            return result;
        sort(candidates.begin(),candidates.end());
        dfs(result,one,candidates,target,0,0);
        return result;
    }
private:
    bool dfs(vector<vector<int>> &result, vector<int> &one, const vector<int> &candidates, const int target, int index, int now) {
        if(now == target)
        {
            result.push_back(one);
            return true;
        }
        if(now > target)
        {
            return false;
        }
        for(int i = index; i < candidates.size(); i ++)
        {
            one.push_back(candidates[i]);
            bool flag = dfs(result,one,candidates,target,i,now+candidates[i]);
            one.pop_back();
            if(flag == false) break;
        }
        return true;
    }
};

#endif