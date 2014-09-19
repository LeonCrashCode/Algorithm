#ifndef NextPermutation_H
#define NextPermutation_H

#include <vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int i = num.size()-2;
		for(; i >=0; i --)
		{
			if(num[i] < num[i+1]) break;
		}
		if(i == -1)
		{
			reverse(num.begin(),num.end());
			return;
		}
		int j = num.size()-1;
		for(; j >=0; j --)
		{
			if(num[j]>num[i])
			{
				swap(num[j], num[i]);
				break;
			}
		}
		reverse(num.begin()+i+1,num.end());

	}
};

#endif