#ifndef DistinctSubsequences_H
#define DistinctSubsequences_H

#include <string>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		if(S.size() == 0) return 0;
		if(T.size() == 0) return 1;
		const int ns = S.size();
		const int nt = T.size();
		int dp[ns][nt];

		for(int i = 0; i < ns; i ++)
		{
			for(int j = 0; j < nt; j ++)
			{
				if(S[i] == T[j])
				{
					if(i-1<0&&j-1<0) dp[i][j] = 1;
					else if(j-1<0) dp[i][j] = 1+dp[i-1][j];
					else if(i-1<0) dp[i][j] = 0;
					else
					{
						dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
					}
				}
				else
				{
					if(i-1<0)
						dp[i][j] = 0;
					else
						dp[i][j] = dp[i-1][j];
				}
			}
		}
		return dp[ns-1][nt-1];
	}
};

#endif