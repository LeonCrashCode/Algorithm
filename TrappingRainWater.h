#ifndef TrappingRainWater_H
#define TrappingRainWater_H

#include <vector>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if(n == 0 || n == 1) return 0;
        
        int maxheight = 0;
        vector<int> capable(n,10000000);
        for(int i = 0; i < n; i ++)
        {
            capable[i] = min(capable[i],maxheight);
            maxheight = max(maxheight,A[i]);
        }
        maxheight = 0;
        for(int i = n-1; i >=0 ; i --)
        {
            capable[i] = min(capable[i],maxheight);
            maxheight = max(maxheight,A[i]);
        }
        int result = 0;
        for(int i = 0; i < n; i ++)
        {
            result += capable[i]-A[i]>=0 ? capable[i]-A[i]:0;
        }
        return result;
    }
};

#endif