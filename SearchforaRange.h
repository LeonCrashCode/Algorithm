#ifndef SearchforaRange_H
#define SearchforaRange_H

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {

		int lowindex = low(A,0,n,target);
		int upindex = up(A,0,n,target);

		if(lowindex == n || upindex == 0 ||A[lowindex]!=target) return vector<int>{-1,-1};
		return vector<int> {lowindex,upindex-1};
	}
private:
	int low(int A[], int start, int end, int target) {
		int left = start;
		int right = end;
		while(left!=right)
		{
			int mid = left+(right-left)/2;
			if(target>A[mid]) left = mid+1;
			else right = mid;
		}
		return left;
	}
	int up(int A[], int start, int end, int target) {
		int left = start;
		int right = end;
		while(left!=right)
		{
			int mid = left+(right-left)/2;
			if(target>=A[mid]) left = mid+1;
			else right = mid;
		}
		return left;
	}
};

#endif