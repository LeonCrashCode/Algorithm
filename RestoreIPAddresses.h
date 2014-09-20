#ifndef RestoreIPAddresses_H
#define RestoreIPAddresses_H

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip="";
        dfs(s,0,0,ip,result);
        return result;
    }
private:
    void dfs(string s, int start, int step, string ip, vector<string> &result) {
        if(start == s.size()) {
            if(step == 4)
                result.push_back(ip.substr(0,ip.size()-1));
            return;
        }
        if(step>4) return;
        
        int ip_part = 0;
        for(int i = start; i < s.size(); i ++)
        {
            ip_part = ip_part*10+(s[i]-'0');
            if(ip_part<=255)
            {
                ip += s[i];
                dfs(s,i+1,step+1,ip+'.',result);
            }
            else
            {
                break;
            }
            if(ip_part == 0) break;
        }
    }
};
#endif