#ifndef SubsetsII_H
#define SubsetsII_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> result;
        vector<int> path;
        if(S.size() == 0) return result;
        
        sort(S.begin(),S.end());
        
        vector<int> flag;
        vector<int> nS;
        
        flag.push_back(1);
        nS.push_back(S[0]);
        
        for(int i = 1; i < S.size(); i ++)
        {
            if(S[i] == S[i-1]) flag[flag.size()-1] += 1;
            else
            {
                nS.push_back(S[i]);
                flag.push_back(1);
            }
        }
        dfs(nS, flag, 0, path, result); 
    }
private:
    void dfs(const vector<int> &nS, const vector<int> &flag, int step, vector<int> &path, vector<vector<int>> &result) {
        if(step == nS.size()) {
            result.push_back(path);
            return ;
        }
        for(int i = 0; i <= flag[step]; i ++) {
            for(int j = 0; j < i; j ++) {
                path.push_back(nS[step]);
            }
            dfs(nS,flag,step+1,path,result);
            for(int j = 0; j < i; j ++) {
                path.pop_back();
            }
        }
    }
};

#endif