// 2022/09/15
// 直接抄书中答案 使用动态规划
// 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int book[1000] = {0};
    int nums[50000];
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;

        for(int i=0; i<1000; ++i)book[i] = -1;
        nums[0] = 1;
        book[s[0]] = 0;
        for(int i=1; i<s.size(); ++i){
            if(book[s[i]]==-1){
                nums[i] = nums[i-1] + 1;
            }else{
                int d = i - book[s[i]];
                if(d>nums[i-1]){
                    nums[i] = nums[i-1] + 1;
                }else{
                    nums[i] = d;
                }    
            }
            book[s[i]] = i;
        }
        
        int value = -1;
        for(int i=0; i<s.size(); ++i){
            value = max(value, nums[i]);
        }

        return value;
    }
};

int main()
{      
    string s = "pwwkew";

    Solution sol;
    cout<<sol.lengthOfLongestSubstring(s)<<endl;

    system("pause");
    return 0;
}