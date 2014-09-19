#ifndef Searcha2DMatrix_H
#define Searcha2DMatrix_H

#include <vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int row = 0;
		while(row<matrix.size())
		{
			if(matrix[row][0] == target) return true;

			if(matrix[row][0]>target)
			{
				break;
			}
			row+=1;
		}
		if(row == 0) return false;
		for(int j = 0; j < matrix[row-1].size(); j ++)
		{
			if(target == matrix[row-1][j]) return true;
		}
		return false;

	}
};
#endif