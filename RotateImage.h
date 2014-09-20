#ifndef RotateImage_H
#define RotateImage_H

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        
        int n = matrix.size();
        int shrink = 0;
        int i;
        int j;
        int i2;
        while(shrink<n-shrink)
        {
            if(shrink == n - shrink - 1)
            {
                break;
            }
            for(j = shrink+1,i=n-shrink-2; j < n-shrink-1 && i >= shrink+1; j ++, i --)
                swap(matrix[shrink][j],matrix[i][shrink]);
            for(i = shrink+1,i2=n-shrink-2; i < n-shrink-1 && i2 >= shrink+1; i ++, i2 --)
                swap(matrix[i][n-shrink-1],matrix[i2][shrink]);
            for(j = n-shrink-2, i = n-shrink-2; j >= shrink+1 && i >= shrink+1; j --, i --)
                swap(matrix[i][shrink],matrix[n-shrink-1][j]);
                
            //corner
            int tmp = matrix[shrink][shrink];
            swap(matrix[shrink][n-shrink-1],tmp);
            swap(matrix[n-shrink-1][n-shrink-1],tmp);
            swap(matrix[n-shrink-1][shrink],tmp);
            swap(matrix[shrink][shrink],tmp);
            shrink+=1;
        }
    }
};

#endif