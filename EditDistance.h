#ifndef EditDistance_H
#define EditDistance_H

#include <string>
using namespace std;


class Solution {
public:
	int minDistance(string word1, string word2) {
		if(word1.size()==0 || word2.size()==0) return max(word1.size(),word2.size());

		const int n = word1.size()+1;
		const int m = word2.size()+1;
		int dp[n][m];
		for(int i = 0; i < n; i ++) dp[i][0] = i;
		for(int j = 0; j < m; j ++) dp[0][j] = j;
		int cost;
		for(int i = 1; i < n; i ++)
		{
			for(int j = 1; j < m; j ++)
			{
				if(word1[i-1] == word2[j-1]) cost = 0;
				else cost = 1;
				dp[i][j] = min(min(dp[i-1][j-1]+cost,dp[i-1][j]+1),dp[i][j-1]+1);
			}
		}
		return dp[n-1][m-1];
	}
};
#endif