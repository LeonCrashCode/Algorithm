#ifndef RemoveDuplicatesfromSortedArray_H
#define RemoveDuplicatesfromSortedArray_H

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int i = 1;
		int index = 1;
		while(i<n)
		{
			if(A[i] == A[i-1])
			{
				i += 1;
			}
			else
			{
				A[index++] = A[i];
				i += 1;
			}
		}
		return min(index,n);
	}
};

#endif