// 2022/08/15
// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
// 比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> nums;
        int maxNum = pow(10, n)-1;
        for(int i=1; i<=maxNum; ++i)
            nums.push_back(i);
        
        return nums;
    }
};

int main()
{   
    Solution sol;
    sol.printNumbers(2);

    system("pause");
    return 0;
}