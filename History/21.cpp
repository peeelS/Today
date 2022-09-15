// 2022/08/19
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// Custom
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int idx = 0;
        for(int i=0; i<nums.size(); ++i){
            int val = nums[i];
            if(val&0x1 ==1){
                nums[i] = nums[idx];
                nums[idx] = val;
                idx++;
            }
        }

        return nums;
    }
};

// 参考书中 双指针
class Solution0{
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while(i<j){
            if((nums[i]&0x1)==1){
                ++i;
                continue;
            }
            if((nums[j]&0x1)==0){
                --j;
                continue;
            }

            int val = nums[i];
            nums[i] = nums[j];
            nums[j] = val;
            ++i;--j;
        }
 
        return nums;
    }
};


int main()
{  
  
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    sol.exchange(nums);
    for(int i=0; i<nums.size(); ++i)cout<<nums[i]<<endl;

    system("pause");
    return 0;
}