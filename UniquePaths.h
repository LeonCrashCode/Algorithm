#ifndef UniquePaths_H
#define UniquePaths_H

#include <vector>
using namespace std;


class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m,vector<int>(n,0));
		dp[0][0]=1;
		for(int i = 0; i < m; i ++) {
			for(int j = 0; j < n; j ++) {
				if(i-1>=0 && j-1>=0) {
					dp[i][j] = dp[i-1][j]+dp[i][j-1];
				}
				else if(i-1>=0) {
					dp[i][j] = dp[i-1][j];
				}
				else if(j-1>=0) {
					dp[i][j] = dp[i][j-1];
				}

			}
		}
		return dp[m-1][n-1];
	}
};

#endif