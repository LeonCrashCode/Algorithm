#ifndef CountandSay_H
#define CountandSay_H

#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if(n == 0) return "";
		if(n == 1) return "1";

		string result = "1";
		for(int i = 2; i <=n; i ++)
		{
			char now = result[0];
			string tmp = "";
			int cnt = 1;
			for(int j = 1; j < result.size(); j ++)
			{
				if(result[j] == now)
				{
					cnt += 1;
				}
				else
				{
					tmp += num2str(cnt)+now;
					now = result[j];
					cnt = 1;
				}
			}
			result = tmp+num2str(cnt)+now;
		}
		return result;
	}
private:
	string num2str(int cnt) {
		string re="";
		while(cnt!=0)
		{
			re = (char)((cnt%10)+'0')+re;
			cnt = cnt/10;
		}
		return re;
	}
};

#endif