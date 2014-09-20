#ifndef JumpGame_H
#define JumpGame_H


class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 1) return true;
        int maxlength = 0;
        for(int i = 0; i <= maxlength; i ++)
        {
            maxlength = max(maxlength,i+A[i]);
            if(maxlength >= n-1) return true;
        }
        return false;
    }
};

#endif