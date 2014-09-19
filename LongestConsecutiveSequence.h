#ifndef LongestConsecutiveSequence_H
#define LongestConsecutiveSequence_H

#include <vector>
using namespace std;

class Solution {
public:

	int longestConsecutive(vector<int> &num) {
		if(num.size() == 0) return 0;
		unordered_map<int,int> M;
		int l = 1;
		for(int i = 0; i < num.size(); i ++)
		{
			if(M.find(num[i]) != M.end()) continue;
			M[num[i]]=1;
			if(M.find(num[i]+1) != M.end())
			{
				l = max(l,merge(M,num[i],num[i]+1));
			}
			if(M.find(num[i]-1) != M.end())
			{
				l = max(l,merge(M,num[i]-1,num[i]));
			}
		}
		return l;
	}
private:
	int merge(unordered_map<int,int> &M, int left, int right) {
		int high = right + M[right] - 1;
		int low = left - M[left] + 1;
		int length = high-low+1;
		M[high] = length;
		M[low] = length;
		return length;
	}
};
#endif