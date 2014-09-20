#ifndef WordLadder_H
#define WordLadder_H

#include <queue>
#include <unordered_set>
using namespace std;


class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<pair<string,int>> q;
		unordered_set<string> flag;
		q.push(make_pair(start,1));
		flag.insert(start);
		while(q.empty()==false)
		{
			pair<string,int> top = q.front();
			q.pop();
			if(top.first == end) return top.second;

			for(int i = 0; i < top.first.size(); i ++)
			{
				for(char c = 'a'; c <= 'z'; c ++)
				{
					swap(c,top.first[i]);
					if(flag.find(top.first) == flag.end() && dict.find(top.first) != dict.end())
					{
						flag.insert(top.first);
						q.push(make_pair(top.first,top.second+1));
					}
					swap(c,top.first[i]);
				}
			}
		}
		return 0;
	}
};
#endif