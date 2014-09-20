#ifndef MaximalRectangle_H
#define MaximalRectangle_H

#include <vector>
using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0) return 0;
        
        
        const int n = matrix.size();
        const int m = matrix[0].size();
        
        vector<int> dp[n];
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                dp[i].push_back(0);
        
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++ ) {
                if(matrix[i][j] == '1')
                {
                    if(i == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j]+1;
                }
            }
        }
        
        int result = -1;
        for(int i = 0; i < n; i ++) {
            result = max(result,largestRectangleArea(dp[i]));
        }
        return result;
    }
private:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(-1);
        int result = 0;
        
        int i = 0;
        while(i<height.size())
        {
            if(s.empty())
                s.push(i++);
            else if(height[i]>=height[s.top()])
                s.push(i++);
            else
            {
                int index = s.top();
                s.pop();
                if(s.empty())
                {
                    result = max(result,height[index]*i);
                }
                else
                {
                    result = max(result,height[index]*(i-s.top()-1));
                }
            }
        }
        return result;
    }
};

#endif