#ifndef WordLadderII_H
#define WordLadderII_H

#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		queue<pair<pair<string,int>,vector<string> > > q;
		unordered_set<string> flag;
		vector<string> tmp;
		tmp.push_back(start);
		q.push(make_pair(make_pair(start,1),tmp));
		flag.insert(start);
		vector<vector<string> > result;

		int Min = 20000;
		while(q.empty()==false)
		{
			pair<pair<string,int>,vector<string> > top = q.front();
			q.pop();
			if(top.first.second > Min) break;

			if(top.first.first == end)
			{
				if(Min == 20000) Min = top.first.second;
				result.push_back(top.second);
			}

			for(int i = 0; i < top.first.first.size(); i ++)
			{
				for(char c = 'a'; c <= 'z'; c ++)
				{
					swap(c,top.first.first[i]);
					if(flag.find(top.first.first) == flag.end() && dict.find(top.first.first) != dict.end())
					{
						flag.insert(top.first.first);
						top.second.push_back(top.first.first);
						q.push(make_pair(make_pair(top.first.first,top.first.second+1),top.second));
						top.second.pop_back();
					}
					swap(c,top.first.first[i]);
				}
			}
		}
		return result;
	}
};

#endif