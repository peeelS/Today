// 2022/09/14
// 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0)
// 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格
// 直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？


#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==1 || n==1){
            int sum_ = 0;
            for(int i=0; i<m; ++i)
                for(int j=0; j<n; ++j)
                    sum_ += grid[i][j];
            return sum_;
        }

        for(int i=m-1; i>=0; --i){
            if(i==m-1)continue;
            grid[i][n-1] += grid[i+1][n-1];
        }
        for(int j=n-1; j>=0; --j){
            if(j==n-1)continue;
            grid[m-1][j] += grid[m-1][j+1];
        }
        
        int mb = max(m-2, 0);
        int nb = max(n-2, 0);
        while(mb>=0 && nb>=0){
            // lie
            for(int i=mb; i>=0; --i){
                grid[i][nb] += max(grid[i+1][nb], grid[i][nb+1]); 
            }
            // hang
            for(int j=nb-1; j>=0; --j){
                grid[mb][j] += max(grid[mb][j+1], grid[mb+1][j]);
            }

            mb--;
            nb--;
        }


        return grid[0][0];
    }
};

int main()
{   
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution sol;
    cout<<sol.maxValue(grid)<<endl;

    system("pause");
    return 0;
}