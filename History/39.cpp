// 2022/09/08
// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool book[100000] = {0};
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len==1)return nums[0];
        for(int i=0; i<len; ++i){
            int sum = 1;
            if(book[i]==true)continue;
            for(int j=i+1; j<len; ++j){
                if(book[j]==false && nums[i]==nums[j]){
                    book[j] = true;
                    ++sum;
                }
                if(sum > len/2.0)return nums[i];
            }
            
        }

        return -1;
    }
};

int main()
{   
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Solution sol;
    cout<<sol.majorityElement(nums)<<endl;

    system("pause");
    return 0;
}