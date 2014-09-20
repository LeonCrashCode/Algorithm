#ifndef WordSearch_H
#define WordSearch_H

#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.size() == 0) return false;
        
        const int n = board.size();
        const int m = board[0].size();
        
        vector<vector<bool>> flag(n,vector<bool>(m,false));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(dfs(board,flag,i,j,0,word)) return true;
        return false;
    }
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &flag, int i,int j, int index, const string &word) {
        if(index == word.size()) return true;
        
        if(i<0 || i>=board.size() || j<0 || j >=board[0].size()) return false;
        
        if(flag[i][j]) return false;
        if(board[i][j] != word[index]) return false;
        
        flag[i][j] = true;
        
        bool r = dfs(board,flag,i+1,j,index+1,word) || dfs(board,flag,i,j+1,index+1,word) || dfs(board,flag,i-1,j,index+1,word) || dfs(board,flag,i,j-1,index+1,word);
        
        flag[i][j] = false;
        return r;
    }
};

#endif