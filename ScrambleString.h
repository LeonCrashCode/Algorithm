#ifndef ScrambleString_H
#define ScrambleString_H

#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int size = s1.size();
        bool dp[size+1][size][size];
        memset(dp,false,sizeof(dp));
        
        for(int i = 0; i < s1.size(); i ++) {
            for(int j = 0; j < s2.size(); j ++) {
                if(s1[i] == s2[j]) dp[1][i][j] = true;
            }
        }
        for(int l = 2; l <= size; l ++) {
            for(int i = 0; i + l <= size; i ++) {
                for(int j = 0; j + l <= size; j ++) {
                    for(int k = 1; k < l; k ++) {
                        if((dp[k][i][j] && dp[l-k][i+k][j+k]) || (dp[k][i][j+l-k]&&dp[l-k][i+k][j]))
                        {
                            dp[l][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[size][0][0];
    }
};

#endif