#ifndef Subsets_H
#define Subsets_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> result;
        vector<int> path;
        
        dfs(S,0,result,path);
        return result;
    }
private:
    void dfs(const vector<int> &S, int step, vector<vector<int>> &result, vector<int> &path) {
        if(step == S.size()) {
            result.push_back(path);
			return;
        }
        
        dfs(S,step+1,result,path);
        
        path.push_back(S[step]);
        dfs(S,step+1,result,path);
        path.pop_back();    
    }
};
#endif