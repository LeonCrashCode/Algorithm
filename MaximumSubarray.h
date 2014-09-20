#ifndef MaximumSubarray_H
#define MaximumSubarray_H

class Solution {
public:
	int maxSubArray(int A[], int n) {

		if(n == 0) return 0;

		int result = -10000000;
		int part = 0;
		for(int i = 0; i < n; i ++) {
			part += A[i];
			if(result < part) result = part;
			if(part < 0) part = 0;

		}
		return result;

	}
};

#endif