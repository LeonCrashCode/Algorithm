#ifndef SearchinRotatedSortedArrayII_H
#define SearchinRotatedSortedArrayII_H

class Solution {
public:
    int search(int A[], int n, int target) {
        for(int i = 0; i < n; i ++)
        {
            if(A[i] == target)
            {
                return true;
            }
        }
        return false;
    }
	/*
	int search(int A[], int n, int target) {
        int first = 0;
        int last = n;
        while(first != last)
        {
            int mid = (first+last)/2;
            if(A[mid] == target) return true;
            
            if(A[first] < A[mid]) {
                if(A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid+1;
            }
            else {
                if(A[mid] < target && target <= A[last-1])
                    first = mid +1;
                else
                    last = mid;
            }
            else {
                first += 1;
            }
        }
        return false;
        
    }
	*/
};

#endif