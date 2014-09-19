#ifndef SqrtLR_H
#define SqrtLR_H

class Solution {
public:
	int sqrt(int x) {
		if(x==0 || x==1) return x;

		int first = 1;
		int last = x/2;
		int last_mid = -1;
		while(first<=last)
		{
			int mid = first+(last-first)/2;
			if(x/mid == mid) return mid;

			if(x/mid < mid) last = mid-1;
			else
			{
				first = mid+1;
				last_mid = mid;
			}
		}
		return last_mid;
	}
};
#endif