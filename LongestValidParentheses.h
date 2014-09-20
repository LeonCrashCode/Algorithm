#ifndef LongestValidParentheses_H
#define LongestValidParentheses_H

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {

		stack<int> S;
		int begin = -1;
		int result = 0;
		for(int i = 0; i < s.size(); i ++)
		{
			if(s[i]=='(') S.push(i);
			else
			{
				if(S.empty()) begin = i;
				else
				{
					S.pop();
					if(S.empty())
						result = max(result,i-begin);
					else
						result = max(result,i-S.top());

				}
			}
		}
		return result;
	}
};

#endif