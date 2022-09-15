// 2022/08/12
// 给定一个 m x n 二维字符网格 board和一个字符串单词 word
// 如果 word 存在于网格中，返回 true ；否则，返回 false 
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
// 同一个单元格内的字母不允许被重复使用。
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool book[10][10];
    int steps[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool dfs(int x, int y, int idx, vector<vector<char>>& board, string word){
        if(idx==word.size()-1)return true;
        int m = board.size();
        int n = board[0].size();
        int target = word[idx+1];
        bool ret = false;
        for(int i=0;i<4;++i){
            int tmpX = x + steps[i][0];
            int tmpY = y + steps[i][1];
            if(tmpX>=0 && tmpX<m && tmpY>=0 && tmpY<n && book[tmpX][tmpY]==false && board[tmpX][tmpY]==target){
                book[tmpX][tmpY]=true;
                ret += dfs(tmpX, tmpY, idx+1, board, word);
                book[tmpX][tmpY]=false;
            }
        }
        return ret;

    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0 || board[0].size()==0 || word.size()==0)return false;
        int m = board.size();
        int n =  board[0].size();
        int len =  word.size();

        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(board[i][j]==word[0]){
                    book[i][j] = true;
                    if(dfs(i, j, 0, board, word))return true;
                    book[i][j] = false;

                }

        return false;
    }
};

int main()
{
    vector<vector<char>> board = {{'a', 'b'}, {'d', 'c'}};
    string word = "abcd";
    Solution sol;
    cout<<sol.exist(board, word)<<endl;

    system("pause");
    return 0;
}