// 2022/09/07-2022/09/08  第一天没做出来 看了题解 第二天重写
// 输入一个字符串，打印出该字符串中字符的所有排列。
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> ret;
    int len = 0;
    int ele[1000] = {0};
    void dfs(string& tmp){
        if(tmp.size()==len){
            ret.push_back(tmp);
            return;
        }
        for(int i=0; i<200; ++i){
            if(ele[i]>0){
                ele[i]--;
                tmp = tmp + (char(i));

                dfs(tmp);

                tmp.pop_back();
                ele[i]++;
            }
        }
    }

    vector<string> permutation(string s) {
        len  = s.size();
        if(len==0)return ret;
        if(len==1){
            ret.push_back(s);
            return ret;
        }
        for(int i=0; i<len; ++i)ele[s[i]]++;
        string tmp;
        dfs(tmp);

        return ret;
    }
};

int main()
{   
    string s = "aaa";
    Solution sol;
    vector<string> ret = sol.permutation(s);
    for(int i=0; i<ret.size(); ++i)cout<<ret[i]<<endl;

    system("pause");
    return 0;
}