#ifndef SurroundedRegions_H
#define SurroundedRegions_H

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>> &board) {
		for(int i = 0; i < board.size(); i ++)
		{
			for(int j = 0; j < board[i].size(); j ++)
			{
				if(board[i][j] == 'O')
				{
					BFS(i,j,board);
				}
			}
		}
		for(int i = 0; i < board.size(); i ++)
		{
			for(int j = 0; j < board[i].size(); j ++)
			{
				if(board[i][j] == 'L')
				{
					board[i][j] = 'O';
				}
			}
		}
	}
private:
	void BFS(int i,int j,vector<vector<char>> &board) {
		queue<pair<int,int>> q;
		q.push(make_pair(i,j));
		vector<pair<int,int>> List;

		bool flag = false;
		board[i][j] = 'L';
		List.push_back(make_pair(i,j));
		while(q.empty()==false)
		{
			pair<int,int> top = q.front();
			q.pop();


			if(top.first-1<0 || top.first+1>=board.size() || top.second-1<0 || top.second+1>=board[0].size()) flag = true;

			if(top.first-1>=0 && board[top.first-1][top.second] == 'O')
			{
				board[top.first-1][top.second] = 'L';
				List.push_back(make_pair(top.first-1,top.second));
				q.push(make_pair(top.first-1,top.second));
			}
			if(top.first+1<board.size() && board[top.first+1][top.second] == 'O')
			{
				board[top.first+1][top.second] = 'L';
				List.push_back(make_pair(top.first+1,top.second));
				q.push(make_pair(top.first+1,top.second));
			}
			if(top.second-1>=0 && board[top.first][top.second-1] == 'O')
			{
				board[top.first][top.second-1] = 'L';
				List.push_back(make_pair(top.first,top.second-1));
				q.push(make_pair(top.first,top.second-1));
			}

			if(top.second+1<board[0].size() && board[top.first][top.second+1] == 'O')
			{
				board[top.first][top.second+1] = 'L';
				List.push_back(make_pair(top.first,top.second+1));
				q.push(make_pair(top.first,top.second+1));
			}

		}
		if(flag ==false)
		{
			for(int i = 0; i < List.size(); i ++)
			{
				board[List[i].first][List[i].second]='X';
			}
		}
	}
};

#endif