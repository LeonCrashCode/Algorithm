#ifndef JumpGameII_H
#define JumpGameII_H

class Solution {
public:
    int jump(int A[], int n) {
        if(n==1) return 0;
    
        int left = 0;
        int right = 0;
        int pre_right = 0;
        //BFS
        int depth = 0;
        while(left<=right)
        {
            ++depth;
            pre_right =  right;
            for(int i = left; i <= pre_right; i ++)
            {
                if(i+A[i]>=n-1) return depth;
                if(i+A[i]>right) right = i+A[i];
            }
            left = pre_right +1;
        }
        return 0;
    }
};

#endif