#ifndef TextJustification_H
#define TextJustification_H

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
		if(words.size() == 0) return result;

		int length = 0;
		int start = 0;
		for(int i =0; i < words.size();)
		{
			if(length+words[i].size()+1>(L+1))
			{
				push_result(result, start, i, words, L, length);
				length = 0;
				start = i;

			}
			else
			{
				length += words[i].size()+1;
				i++;
			}
		}
		string tmp = words[start];
		for(int i = start+1; i < words.size(); i ++) tmp += " "+words[i];
		int extra = L-tmp.size();
		for(int i = 0; i < extra; i ++) tmp+=" ";
		result.push_back(tmp);

		return result;
	}
private:
	void push_result(vector<string> &result, int start, int i, const vector<string> &words, int L, int length) {
		string tmp = "";
		if(i-start == 1)
		{
			tmp += words[start];
			for(int k = 0; k < L-words[start].size(); k ++) tmp+=" ";
			result.push_back(tmp);
		}
		else if(i-start == 2)
		{
			tmp += words[start];
			for(int k = 0; k < L-words[start].size()-words[start+1].size(); k ++) tmp+=" ";
			tmp += words[start+1];
			result.push_back(tmp);
		}
		else
		{

			int rest = (L-(length-(i-start)))%(i-start-1);
			int space = (L-(length-(i-start)))/(i-start-1);
			for(int j = start; j < i-1; j ++)
			{
				tmp += words[j];
				for(int k = 0; k < space; k ++) tmp+=" ";
				if(rest!=0)
				{
					tmp +=" ";
					rest -=1;
				}
			}
			tmp+=words[i-1];
			result.push_back(tmp);
		}
	}

};

#endif