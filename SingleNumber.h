#ifndef SingleNumber_H
#define SingleNumber_H

class Solution {
public:
    int singleNumber(int A[], int n) {
        int sum = 0;
        for(int i = 0; i < n; i ++)
        {
            sum = sum ^ A[i];
        }
        return sum;
    }
};

#endif