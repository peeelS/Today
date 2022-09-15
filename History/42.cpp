// 2022/09/12
// 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
// 要求时间复杂度为O(n)

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_value = nums[0];
        int sum_ = 0;
        for(int i=0; i<nums.size(); ++i){
            max_value = max(max_value, nums[i]);
            if(sum_ + nums[i] < 0){
                sum_ = 0;
                continue;
            }

            sum_ = sum_ + nums[i];
            max_value = max(max_value, sum_);
        }

        return max_value;
    }
};

int main()
{   
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    cout<<sol.maxSubArray(nums)<<endl;

    system("pause");
    return 0;
}