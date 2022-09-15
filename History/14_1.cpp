#include <vector>
#include <iostream>
using namespace std;

// 2022/08/12 数学瞎搞法
class Solution0 {
public:
    int cuttingRope(int n){
        if(n==2)return 1;
        int m = int(n/e);
        int ret = 1;
        for(int i=-1; i<2; ++i){
            int mm = m + i;
            int yushu = n%mm;
            int shang = n/mm;
            int sum = 1;
            for(int j=0;j<mm;++j){
                int tmpValue = (((yushu--)>0)?1:0) + shang;
                sum = sum*tmpValue;
            }
            ret = max(ret, sum);
        }

        return ret;
    }

private:
    const float e = 2.71;
};

// 2022/08/19 参考书籍
class Solution {
public:

    int nums[100] = {0};
    int cuttingRope(int n) {
        nums[2] = 1;
        nums[3] = 2;
        if(n<=3)return nums[n];

        for(int i=4; i<=n; ++i){
            for(int j=1; j<=i-2; ++j){
                nums[i] = max(nums[i], j*max(nums[i-j], i-j));
            }
        }

        return nums[n];

    }
};

int main()
{
    int n=8;
    Solution sol;
    cout<<sol.cuttingRope(n)<<endl;

    system("pause");
    return 0;
}