#ifndef RemoveElement_H
#define RemoveElement_H
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int i = 0;
		int j = n-1;
		int count = 0;
		while(i<=j)
		{
			if(A[j] == elem)
			{
				j--;
				count+=1;
				continue;
			}
			if(A[i] == elem)
			{
				swap(A[i],A[j]);
				count += 1;
				i ++;
				j --;
				continue;
			}
			else
			{
				i ++;
			}
		}
		return n-count;

	}
};
#endif