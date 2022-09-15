// 2022/09/12
// 数据范围总受限 对特例不断修改才成功
// 数字以0123456789101112131415…的格式序列化到一个字符序列中。
// 在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
// 请写一个函数，求任意第n位对应的数字

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9)return n;

        long long len_b = 0;
        long long len = 10;
        int i = 1;
        while(n>=len)
        {   
            len_b = len;
            ++i;
            len = len + (pow(10, i)-pow(10, i-1))*i;
          
        }
        int num_idx = (n-len_b+1)/i;
        int digit_idx = (n-len_b+1)%i;
        if(digit_idx != 0)++num_idx;
        if(digit_idx == 0)digit_idx = i;
        int num_value = pow(10, i-1) + num_idx - 1;

        num_value = num_value/(pow(10, i-digit_idx));
        
        return (num_value%10);
    }
};

int main()
{   
   Solution sol;

   cout<<sol.findNthDigit(2147483647)<<endl;

    system("pause");
    return 0;
}