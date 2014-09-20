#ifndef FirstMissingPositive_H
#define FirstMissingPositive_H

#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n ; i++)
        {
            if(A[i] <= 0 || A[i] == i+1 || A[i] >= n) continue;
            
            if(A[A[i]-1] == A[i])
            {
                A[i] = -1;
                continue;
            }
            swap(A[A[i]-1],A[i]);
            i -- ;
        }
        for(int i = 0; i < n; i ++)
        {
            if(A[i]!=i+1) return i+1;
        }
        return n+1;
    }
};

#endif