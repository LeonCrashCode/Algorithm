#ifndef MinimumWindowSubstring_H
#define MinimumWindowSubstring_H

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		if(S.size() == 0) return "";
		if(S.size() < T.size()) return "";

		vector<int> tset(256,0);
		vector<int> sset(256,0);

		for(int i = 0; i < T.size(); i ++) tset[T[i]] += 1;

		int start = 0;
		int cover = 0;
		int result_start = -1;
		int result_length = S.size()+1;
		for(int end = 0; end < S.size(); end ++)
		{
			if(tset[S[end]]>0)
			{
				sset[S[end]]+=1;
				if(sset[S[end]]<=tset[S[end]]) cover += 1;
			}
			if(cover == T.size())
			{
				while(sset[S[start]]>tset[S[start]] || tset[S[start]] == 0)
				{
					if(sset[S[start]]>tset[S[start]]) sset[S[start]] -= 1;
					start += 1;
				}
				if(result_length>end-start+1)
				{
					result_length = end-start+1;
					result_start = start;
				}

			}
		}
		if(result_length == S.size()+1) return "";
		return S.substr(result_start,result_length);

	}
};

#endif