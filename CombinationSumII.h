#ifndef CombinationSumII_H
#define CombinationSumII_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> result;
        vector<int> one;
        if(num.size() == 0)
            return result;
        sort(num.begin(),num.end());
        
        vector<int> count(num.size(),0);
        vector<int> candidates;
        candidates.push_back(num[0]);
        count[0] = 1;
        int index =0 ;
        for(int i = 1; i < num.size(); i ++)
        {
            if(num[i] == num[i-1])
            {
                count[index] += 1;
            }
            else
            {
                count[++index] = 1;
                candidates.push_back(num[i]);
            }
        }
        
        dfs(result,one,candidates,target,0,count,0);
        return result;
    }
private:
    bool dfs(vector<vector<int>> &result, vector<int> &one, const vector<int> &candidates, const int target, int index, const vector<int> &count, int now) {
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
			int cnt = 0;
            for(int j = 0; j < count[i]; j ++)
            {
				bool flag;
				cnt += 1;
                one.push_back(candidates[i]);
                flag = dfs(result,one,candidates,target,i+1,count,now+candidates[i]*(j+1));
                if(flag == false) break;
            }
            for(int j = 0; j < cnt; j ++)
            {
                one.pop_back();
            }
        }
        return true;
    }
};

#endif