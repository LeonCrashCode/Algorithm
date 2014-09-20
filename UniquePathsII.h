#ifndef UniquePathsII_H
#define UniquePathsII_H

#include <vector>
using namespace std;


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if(obstacleGrid.size() == 0) return 0;

		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> dp(m,vector<int>(n,0));
		if(obstacleGrid[0][0] == 1)
			dp[0][0]=0;
		else
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
				if(obstacleGrid[i][j] == 1) dp[i][j] = 0;

			}
		}
		return dp[m-1][n-1];
	}
};

#endif