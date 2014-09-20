#ifndef WordBreakII_H
#define WordBreakII_H

#include "common.h"
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> flag(s.size()+1, false);
        vector< vector<bool> > prev(s.size()+1,vector<bool>(s.size()));
        
        flag[0] = true;
        for(int i = 1; i <=s.size(); i ++)
        {
            for(int j = 0; j < i; j ++)
            {
                if(flag[j]&&dict.find(s.substr(j,i-j))!=dict.end())
                {
                    flag[i] = true;
                    prev[i][j] = true;
                }
            }
        }
        vector<string> tmp;
        vector<string> result;
        DFS(s,prev,tmp,result,s.size());
        return result;
    }
private:
    void DFS(const string s, const vector< vector<bool> > prev, vector<string> &tmp, vector<string> &result, int now) {
        if(now == 0)
        {
            string t = "";
            for(int i = 0; i < tmp.size(); i ++) t=tmp[i]+" "+t;
            result.push_back(t.substr(0,t.size()-1));
        }
        for(int i = 0; i <now; i ++)
        {
            if(prev[now][i] == true)
            {
                tmp.push_back(s.substr(i,now-i));
                DFS(s,prev,tmp,result,i);
                tmp.pop_back();
            }
        }
    }
};

#endif