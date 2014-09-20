#ifndef ValidPalindrome_H
#define ValidPalindrome_H

#include <string>
using namespace std;


class Solution {
public:
	bool isPalindrome(string s) {
		change(s);
		int l = 0;
		int r = s.size()-1;
		while(l<=r)
		{
			if(s[l] != s[r]) return false;
			l ++;
			r --;
		}
		return true;

	}
private:
	void change(string &s) {
		string filters = "";
		for(int i = 0; i < s.size(); i ++)
		{
			if(s[i]<='z' && s[i] >='a')
				filters += s[i];
			else if(s[i]<='Z' && s[i] >='A')
				filters += s[i]+32;
			else if(s[i]<='9' && s[i] >= '0')
				filters += s[i];
		}
		s = filters;
	}
};
#endif