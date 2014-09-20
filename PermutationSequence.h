#ifndef PermutationSequence_H
#define PermutationSequence_H

#include <string>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<char> sequence;
		for(int i = 0; i <n; i ++) {
			sequence.push_back(i+1+'0');
		}
		int base = 1;
		for(int i = 1; i < n; i ++) {
			base *= i;
		}
		string result ="";
		k--;
		for(int i = n-1; i>=1; k%=base, base/=i, i --)
		{
			vector<char>::iterator iter = sequence.begin();
			for(int j = 0;iter!=sequence.end();iter++, j ++)
			{
				if(j == k/base){
					result += sequence[j];
					sequence.erase(iter);
					break;
				}
			}
		}
		result += sequence[0];
		return result;
	}
};

#endif