#ifndef ValidSudoku_H
#define ValidSudoku_H

#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {

		for(int i = 0; i < 9; i ++)
		{
			vector<bool> used(9,false);
			for(int j = 0; j < 9; j ++)
			{
				if(board[i][j] == '.') continue;
				if(used[board[i][j]-'1']) return false;
				used[board[i][j]-'1'] = true;
			}
		}
		for(int j = 0; j < 9; j ++)
		{
			vector<bool> used(9,false);
			for(int i = 0; i < 9; i ++)
			{
				if(board[i][j] == '.') continue;
				if(used[board[i][j]-'1']) return false;
				used[board[i][j]-'1'] = true;
			}
		}

		for(int v_i =0; v_i<3; v_i++)
		{
			for(int v_j = 0; v_j < 3;v_j++)
			{
				vector<bool> used(9,false);
				for(int i = v_i*3; i < (v_i+1)*3; i ++)
				{
					for(int j = v_j*3; j < (v_j+1)*3; j ++)
					{
						if(board[i][j] == '.') continue;
						if(used[board[i][j]-'1']) return false;
						used[board[i][j]-'1'] = true;
					}
				}
			}
		}
		return true;
	}

};

#endif