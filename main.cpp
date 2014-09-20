#include <iostream>
#include <vector>
#include "CombinationSumII.h"
#include <string>
using namespace std;

int main()
{
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(5);
	candidates.push_back(2);
	candidates.push_back(1);
	candidates.push_back(2);

	Solution s;
	vector<vector<int>> result;
	result = s.combinationSum2(candidates,5);
	for(int i = 0; i < result.size(); i ++)
	{
		for(int j = 0; j < result[i].size(); j ++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}