#ifndef SimplifyPath_H
#define SimplifyPath_H

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		if(path.size() == 0) return "";

		vector<string> path_list;
		path+="/";
		int start = 0;
		for(int end = 1; end<path.size(); end ++)
		{
			if(path[end] == '/')
			{
				string action = path.substr(start+1,end-start-1);
				if(action == "..")
				{
					if(path_list.size()!=0)
						path_list.pop_back();
				}
				else if(action != "." && action != "")
				{
					path_list.push_back(action);
				}
				start = end;
			}
		}
		string result = "";
		for(int i = 0; i < path_list.size(); i ++) result+="/"+path_list[i];
		if(result == "") return "/";
		return result;
	}
};

#endif