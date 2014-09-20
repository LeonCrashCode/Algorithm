#ifndef SpiralMatrix_H
#define SpiralMatrix_H
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		if(matrix.size() == 0) return result;

		int minvalidi = 0;
		int maxvalidi = matrix.size();
		int minvalidj = 0;
		int maxvalidj = matrix[0].size();


		int direction = 0;
		int i=0;
		int j=0;
		while(true)
		{
			if(direction == 0)
			{
				if(minvalidj >= maxvalidj) break;
				while(j<maxvalidj) {result.push_back(matrix[i][j]); j++;}
				direction = 1;
				minvalidi += 1;
				i+=1;
				j-=1;
			}
			else if(direction == 1)
			{
				if(minvalidi >= maxvalidi) break;
				while(i<maxvalidi) {result.push_back(matrix[i][j]); i++;}
				direction = 2;
				maxvalidj -= 1;
				j-=1;
				i-=1;
			}
			else if(direction == 2)
			{
				if(minvalidj >= maxvalidj) break;
				while(j>=minvalidj) {result.push_back(matrix[i][j]); j--;}
				direction = 3;
				maxvalidi -= 1;
				i-=1;
				j+=1;
			}
			else
			{
				if(minvalidi >= maxvalidi) break;
				while(i>=minvalidi) {result.push_back(matrix[i][j]); i--;}
				direction = 0;
				minvalidj += 1;
				j+=1;
				i+=1;
			}
		}
		return result;
	}
};

#endif