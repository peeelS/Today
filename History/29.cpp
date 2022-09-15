// 2022/08/26
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
//  1 2  3  4
//  5 6  7  8
//  9 10 11 12
//  13 14 15 16
// 难度是简单 但写了好久 继续加油！
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
   int book[110][110] = {0};
   int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
   int m = 0;
   int n = 0;

   void dfs(vector<vector<int>>& matrix, vector<int>& ret, int i, int j, int direction){
        int sum = 0;
        for(int _i=0; _i<4; ++_i){
            sum += book[1+i+moves[_i][0]][1+j+moves[_i][1]];
        }
        if(sum==4)return;


        int x = i + moves[direction][0];
        int y = j + moves[direction][1];
        if(x>=0 && x<m && y>=0 && y<n && (book[x+1][y+1]==0)){
            book[x+1][y+1] = 1;
            ret.push_back(matrix[x][y]);
            dfs(matrix, ret, x, y, direction);
        }else{
            dfs(matrix, ret, i, j, (direction+1)%4);
        }

   }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size()==0 || matrix[0].size()==0)return ret;
        m = matrix.size(); n = matrix[0].size();

        for(int i=0; i<=n+1; ++i){
            book[0][i] = 1;
            book[m+1][i] = 1;
        }
        for(int i=1; i<=m; ++i){
            book[i][0] = 1;
            book[i][n+1] = 1;
        }

        ret.push_back(matrix[0][0]);
        book[1][1] = 1;
        dfs(matrix, ret, 0, 0, 0);

        return ret;
    }
};


int main()
{   
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Solution sol;

    vector<int> ret = sol.spiralOrder(matrix);
    for(int i=0; i<ret.size(); ++i)cout<<ret[i]<<" ";

    system("pause");
    return 0;
}