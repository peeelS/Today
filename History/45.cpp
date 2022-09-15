// 2022/09/14
// 写不出来 评论区解法 厉害！
// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:

    string minNumber(vector<int>& nums) {
        vector<string> s;
        for(int i=0; i<nums.size(); ++i)s.push_back(to_string(nums[i]));

        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<nums.size()-i-1; ++j){
                string a = s[j];
                string b = s[j+1];
                if( a+b > b+a){
                    s[j] = b;
                    s[j+1] = a;
                }
            }
        }

        string ret;
        for(int i=0; i<nums.size(); ++i)ret += s[i];

        return ret;
    }
};

int main()
{   
    vector<int> nums = {1, 2, 3, 0};

    Solution sol;
    cout<<sol.minNumber(nums)<<endl;

    system("pause");
    return 0;
}