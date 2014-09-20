#ifndef SudokuSolver_H
#define SudokuSolver_H

#include <vector>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		bool flag = dfs(board);

	}
private:
	bool dfs(vector<vector<char>> &board)
	{
		for(int i = 0; i < 9; i ++)
		{
			for(int j = 0; j < 9; j ++)
			{
				if(board[i][j]!='.') continue;
				for(int k = 0; k < 9; k ++)
				{
					if(isvalid(board,i,j,k))
					{
						board[i][j] = '1'+k;
						if(dfs(board))
							return true;
						board[i][j] = '.';
					}

				}
				return false;
			}
		}
		return true;
	}
	bool isvalid(const vector<vector<char>> &board, const int &v_i, const int &v_j, const int &k) {
		for(int j = 0; j < 9; j ++) {
			if(board[v_i][j] == k+'1') return false;
		}
		for(int i = 0; i < 9; i ++) {
			if(board[i][v_j] == k+'1') return false;
		}
		for(int i = (v_i/3)*3; i < (v_i/3+1)*3; i ++)
		{
			for(int j = (v_j/3)*3; j < (v_j/3+1)*3; j ++)
			{
				if(board[i][j] == k+'1') return false;
			}
		}
		return true;
	}
};

#endif