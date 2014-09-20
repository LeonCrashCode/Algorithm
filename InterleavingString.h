#ifndef InterleavingString_H
#define InterleavingString_H

#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        const int n1 = s1.size()+1;
        const int n2 = s2.size()+1;
        bool dp[n1][n2];
        
        dp[0][0] = true;
        for(int i = 1; i <= s1.size() ; i++) {
            if(s1[i-1] == s3[i-1]) dp[i][0] = dp[i-1][0];
            else dp[i][0] = false;
        }
        for(int j = 1; j <= s2.size() ; j++) {
            if(s2[j-1] == s3[j-1]) dp[0][j] = dp[0][j-1];
            else dp[0][j] = false;
        }
        for(int i = 1; i <= s1.size(); i ++) {
            for(int j = 1; j <= s2.size(); j ++) {
                dp[i][j] = (s1[i-1] == s3[i+j-1] && dp[i-1][j])||(s2[j-1] == s3[i+j-1] && dp[i][j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

#endif