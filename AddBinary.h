#ifndef AddBinary_H
#define AddBinary_H

#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int add = 0;
		string result = "";
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int ita = 0;
		int itb = 0;

		while(ita<a.size() && itb < b.size())
		{
			result.insert(result.begin(),((a[ita]-'0')+(b[itb]-'0')+ add)%2 + '0');
			add = ((a[ita]-'0')+(b[itb]-'0')+ add)/2;
			ita++;
			itb++;
		}
		while(ita < a.size())
		{
			result.insert(result.begin(),((a[ita]-'0')+ add)%2 + '0');
			add = ((a[ita]-'0')+ add)/2;
			ita ++;
		}
		while(itb < b.size())
		{
			result.insert(result.begin(),((b[itb]-'0')+ add)%2 + '0');
			add = ((b[itb]-'0')+ add)/2;
			itb++;
		}

		if(add!=0) result.insert(result.begin(),'1');
		return result;
	}
};

#endif