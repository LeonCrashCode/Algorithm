#ifndef SingleNumberII_H
#define SingleNumberII_H

class Solution {
public:
    int singleNumber(int A[], int n) {
        int bit[32];
        for(int i = 0; i < 32; i ++) bit[i] = 0;
        for(int j = 0; j < n; j ++)
        {
            for(int i = 0; i < 32; i ++) 
            {
                bit[i] += (A[j]>>i) & 1;
            }
        }
        for(int i= 0; i < 32; i ++)
        {
            bit[i]%=3;
        }
        int sum = 0;
        for(int i= 0; i < 32; i ++)
        {
            if(bit[i]>0)
                sum += (1<<i);
        }
        return sum;
    }
};

#endif