#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
    int arr[205][205];
public:
    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                memset(arr,0,sizeof(arr));
                if (dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word,int i,int j,int k){
        if (i<0||j<0||i>=board.size()||j>=board[0].size()||arr[i][j])
            return false;

        if (board[i][j]==word[k]){
            arr[i][j]=1;
            if (k==word.size()-1){
                return true;
            }
            bool res= dfs(board,word,i-1,j,k+1)||
                    dfs(board,word,i,j-1,k+1)||
                    dfs(board,word,i+1,j,k+1)||
                    dfs(board,word,i,j+1,k+1);
            if (!res)
                arr[i][j]=0;
            return res;
        }
        return false;
    }
};