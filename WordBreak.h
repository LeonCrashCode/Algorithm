#ifndef WordBreak_H
#define WordBreak_H

#include "common.h"
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> flag(s.size()+1, false);
        flag[0] = true;
        for(int i = 1; i <=s.size(); i ++)
        {
            for(int j = 0; j < i; j ++)
            {
                if(flag[j]&&dict.find(s.substr(j,i-j))!=dict.end())
                {
                    flag[i] = true;
                    break;
                }
            }
        }
        return flag[s.size()];
    }
};

#endif