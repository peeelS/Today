// 2022/09/14
// 给定一个数字，我们按照如下规则把它翻译为字符串：
// 0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
// 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法


#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(string& s, int idx){
        if(idx==s.size()-1 || idx==s.size())return 1;

        int sum_ = dfs(s, idx+1);
        
        int val = stoi(s.substr(idx, 2));
        if(val>=10  && val<=25)sum_ += dfs(s, idx+2);

        return sum_;

    }

    int translateNum(int num) {
        string s = to_string(num);
        return dfs(s, 0);
    }
};

int main()
{   
    int num = 12258;
    Solution sol;
    
    cout<<sol.translateNum(num)<<endl;

    system("pause");
    return 0;
}