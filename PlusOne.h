#ifndef PlusOne_H
#define PlusOne_H
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int add = 1;
		for(int i = digits.size()-1; i >=0; i --)
		{
			digits[i] += add;
			add = digits[i]/10;
			digits[i] = digits[i]%10;
		}
		if(add==1)
		{
			digits.insert(digits.begin(),1);
		}
		return digits;
	}
};

#endif