#ifndef Powxn_H
#define Powxn_H

class Solution {
public:
    double pow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        
        double tmp = pow(x,n/2);
        if(n<0)
        {
            if((-n)%2==1)
            {
                return tmp*tmp/x;
            }
            else
            {
                return tmp*tmp;
            }
        }
        else
        {
            if(n%2==1)
            {
                return tmp*tmp*x;
            }
            else
            {
                return tmp*tmp;
            }
        }
    }
};


#endif