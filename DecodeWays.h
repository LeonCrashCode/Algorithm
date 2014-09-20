#ifndef DecodeWays_H
#define DecodeWays_H

#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0) return 0;
        
        vector<int> flag(s.size()+1,0);
        flag[0] = 1;
        if(s[0]!='0')
            flag[1] = 1;
        
        for(int i = 2; i < s.size()+1; i ++) {
            if(s[i-1] != '0')
                flag[i] += flag[i-1];
            if((s[i-2] == '1' && s[i-1] <='9' && s[i-1] >= '0')||(s[i-2] == '2' && s[i-1] <='6' && s[i-1] >= '0'))
                flag[i] += flag[i-2];
        }
        return flag[s.size()];
    }
};

#endif