#ifndef NQueens_H
#define NQueens_H
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<bool> column(n,false);
		vector<bool> right(2*n,false);
		vector<bool> left(2*n,false);

		vector<vector<string>> result;
		vector<int> one;
		dfs(result,one,0,n,column,right,left);
		return result;
	}
private:
	void dfs(vector<vector<string>> &result, vector<int> &one, int row, const int &n, vector<bool> &column, vector<bool> &right, vector<bool> &left)
	{
		if(row == n)
		{
			vector<string> path;
			for(int i = 0; i < n; i ++)
			{
				string line="";
				for(int j = 0; j < n; j ++)
				{
					if(j!=one[i])
						line += '.';
					else
						line += 'Q';
				}
				path.push_back(line);
			}
			result.push_back(path);
			return ;
		}
		for(int j = 0; j < n; j ++)
		{
			if(column[j] == true || right[row-j+n] == true || left[row+j] == true) continue;

			column[j] = true;
			right[row-j+n] = true;
			left[row+j] = true;
			one.push_back(j);

			dfs(result,one,row+1,n,column,right,left);

			one.pop_back();
			column[j] = false;
			right[row-j+n] = false;
			left[row+j] = false;
		}
	}
};

#endif
