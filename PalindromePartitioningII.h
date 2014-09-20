#ifndef PalindromePartitioningII_H
#define PalindromePartitioningII_H

#include "common.h"
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        const int n = 10;
        bool flag[n][n];
        memset(flag,false,sizeof(flag));
        
        for(int i = 0; i < n; i ++)
        {
            for(int j = i; j >=0; j --)
            {
                flag[j][i] = (s[i]==s[j] && (i-j<2 || flag[j+1][i-1]));
            }
        }
        
        int d[n];
        for(int i = 0; i < n; i ++)
        {
            d[i] = n*2;
        }
        for(int i = 0; i < n; i ++)
        {
            for(int j = i; j >=0; j --)
            {
                if(flag[j][i])
                {
                    if(j-1>=0)
                    {
                        d[i] = min(d[j-1]+1,d[i]);
                    }
                    else
                    {
                        d[i] = min(1,d[i]);
                    }
                }
            }
        }
        return d[n-1]-1;
    }
};

#endif