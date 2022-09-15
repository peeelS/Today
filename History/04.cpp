// 2022/08/08
// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。


#include <iostream>
#include <vector>
using namespace std;

// 官方
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        if(rowNum==0 || colNum==0)return false;

        int row = 0;
        int col = colNum-1;
        while(row<=rowNum-1 && col>=0){
            int value = matrix[row][col];
            if(value==target){
                return true;
            }else if(value < target){
                ++row;
            }else{
                --col;
            }

        }
             
        return false;
    }
};

int main()
{
    vector<vector<int>> mat {{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};


    Solution solution;
    
    bool ret = solution.findNumberIn2DArray(mat, 20);
    cout<<ret<<endl;

    system("pause");
    return 0;
}