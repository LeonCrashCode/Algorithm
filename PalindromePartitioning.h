#ifndef PalindromePartitioning_H
#define PalindromePartitioning_H

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //O(n^2)
    vector<vector<string>> partition(string s) {
        const int n = s.size();
        bool flag[n][n];
        memset(flag,false,sizeof(flag));
        
        for(int i = 0; i < n; i ++)
        {
            for(int j = i; j >=0; j --)
            {
                if(s[i] == s[j] && (i-j<2 || flag[j+1][i-1]))
                {
                    flag[j][i] = true;
                }
            }
        }
        
        vector<vector<string>> result[n];
        for(int i = 0; i < n; i ++)
        {
            for(int j = i; j >=0; j --)
            {
                if(flag[j][i])
                {
                    string p = s.substr(j,i-j+1);
                    
                    if(j-1>=0)
                    {
                        for(int k = 0; k < result[j-1].size(); k ++)
                        {
                            vector<string> tmp = result[j-1][k];
                            tmp.push_back(p);
                            result[i].push_back(tmp);
                        }
                    }
                    else
                    {
                        result[i].push_back(vector<string>{p});
                    }
                }
            }
        }
        return result[n-1];
    }
};

#endif