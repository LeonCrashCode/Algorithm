#ifndef SubstringwithConcatenationofAllWords_H
#define SubstringwithConcatenationofAllWords_H

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		if(S.size() == 0 || L.size() == 0) return result;

		int len = L[0].size();

		unordered_map<string,int> dict;
		for(int i = 0; i < L.size(); i ++) dict[L[i]] += 1;

		int start = 0;
		unordered_map<string,int> used;
		while(true)
		{
			if(start + len*L.size() > S.size()) break;

			int index = 0;
			used.clear();

			for(; index < L.size(); index += 1)
			{
				string tmp = S.substr(start+index*len,len);
				if(dict.find(tmp) == dict.end()) break;

				if(used[tmp] >= dict[tmp]) break;
				used[tmp] += 1;
			}
			if(index == L.size()) result.push_back(start);
			start+=1;
		}
	}
};

#endif