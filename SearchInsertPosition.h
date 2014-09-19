#ifndef SearchInsertPosition_H
#define SearchInsertPosition_H

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int left = 0;
		int right = n;
		while(left!=right)
		{
			int mid = left+(right-left)/2;
			if(target>A[mid]) left = mid+1;
			else right = mid;
		}
		return left;
	}
};

#endif