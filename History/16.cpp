// 2022/08/14
// 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
#include <iostream>
using namespace std;

class Solution {
public:
    double func(double x, unsigned int n){
        if(n==0)return 1;
        if(n==1)return x;
        double sum = func(x, n>>1);
        sum *= sum;
        if((n&0x1)==1) sum *= x;

        return sum;
    }

    double myPow(double x, int n) {
        if(n<0)return 1/x*func(1/x, -(n+1));
        else return func(x, n); 
    }
};

int main()
{
    Solution sol;
    cout<<sol.myPow(-1, -2147483648)<<endl;
    system("pause");
    return 0;
}