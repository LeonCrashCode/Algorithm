#ifndef SpiralMatrix_H
#define SpiralMatrix_H
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int>> matrix(n,vector<int>(n,0));

		int minvalidi = 0;
		int maxvalidi = n;
		int minvalidj = 0;
		int maxvalidj = n;


		int direction = 0;
		int i=0;
		int j=0;
		int index = 1;
		while(true)
		{
			if(direction == 0)
			{
				if(minvalidj >= maxvalidj) break;
				while(j<maxvalidj) {matrix[i][j]=index++; j++;}
				direction = 1;
				minvalidi += 1;
				i+=1;
				j-=1;
			}
			else if(direction == 1)
			{
				if(minvalidi >= maxvalidi) break;
				while(i<maxvalidi) {matrix[i][j]=index++; i++;}
				direction = 2;
				maxvalidj -= 1;
				j-=1;
				i-=1;
			}
			else if(direction == 2)
			{
				if(minvalidj >= maxvalidj) break;
				while(j>=minvalidj) {matrix[i][j]=index++; j--;}
				direction = 3;
				maxvalidi -= 1;
				i-=1;
				j+=1;
			}
			else
			{
				if(minvalidi >= maxvalidi) break;
				while(i>=minvalidi) {matrix[i][j]=index++; i--;}
				direction = 0;
				minvalidj += 1;
				j+=1;
				i+=1;
			}
		}
		return matrix;
	}
};

#endif