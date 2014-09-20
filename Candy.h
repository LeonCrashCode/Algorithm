#ifndef CANDY_H
#define CANDY_H

#include <vector>
using namespace std;


class Solution {
public:
    int candy(vector<int> &ratings) {
        int total = 1;
        int current = 1;
        
        int pre_candy = 1;
        int total_candy = 1;
        int before = 0;
        int max_before = 1;
        for(int i = 1; i < ratings.size(); i ++)
        {
            if(ratings[i] >= ratings[i-1])
            {
                if(ratings[i] > ratings[i-1])
                    pre_candy += 1;
                // == has no constraint
                else
                    pre_candy = 1;
                total_candy += pre_candy;
                max_before = pre_candy;
                before = 0;
            }
            else
            {
                before += 1;
                if(before == max_before)
                    total_candy += before+1;
                else
                    total_candy += before;
                
                if(before == max_before) max_before +=1;
                pre_candy = 1;
            }
        }
        return total_candy;
    }
};

#endif