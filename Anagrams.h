#ifndef Anagrams_H
#define Anagrams_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string,int> Dict;
        vector<string> result;
        for(int i = 0; i < strs.size(); i ++)
        {
            string  tmp= strs[i];
            sort(tmp.begin(),tmp.end());
            if(Dict.find(tmp) != Dict.end())
            {
                if(Dict[tmp]!=-1)
                {
                    result.push_back(strs[Dict[tmp]]);
                    Dict[tmp] = -1;
                }
                result.push_back(strs[i]);
            }
            else
            {
                Dict[tmp] = i;
            }
        }
        return result;
    }
};

#endif