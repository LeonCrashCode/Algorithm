#ifndef LargestRectangleinHistogram_H
#define LargestRectangleinHistogram_H

#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
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