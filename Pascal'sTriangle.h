#ifndef PascalsTriangle_H
#define PascalsTriangle_H
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>> result;
		for(int i = 0; i < numRows; i ++)
		{
			if(i == 0)
			{
				result.push_back(vector<int>{1});
				continue;
			}
			vector<int> one;
			one.push_back(1);
			for(int j = 1; j <= i-1; j ++)
			{
				one.push_back(result.back()[j]+result.back()[j-1]);
			}
			one.push_back(1);
			result.push_back(one);
		}
		return result;
	}

#endif