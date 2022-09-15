// 2022/08/18
// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

// 数值（按顺序）可以分成以下几个部分：

// 若干空格
// 一个 小数 或者 整数
// （可选）一个 'e' 或 'E' ，后面跟着一个 整数
// 若干空格
// 小数（按顺序）可以分成以下几个部分：

// （可选）一个符号字符（'+' 或 '-'）
// 下述格式之一：
// 至少一位数字，后面跟着一个点 '.'
// 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
// 一个点 '.' ，后面跟着至少一位数字
// 整数（按顺序）可以分成以下几个部分：

// （可选）一个符号字符（'+' 或 '-'）
// 至少一位数字
// 部分数值列举如下：

// ["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
// 部分非数值列举如下：

// ["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    int len = 0;

    bool isNumber(string s) {
        len = s.size();
        if(len==0)return false;
        bool flag = false;
        int n = 0;
        
        //space
        if(s[n]==' ')n = moveNums(s, n, 0);

        // zhengShu or xiaoShu
        if(n>=0 && n<len && (s[n]=='-' || s[n]=='+'))++n;
        if(n>=0 && n<len && s[n]>='0' && s[n]<='9'){
            flag = true;
            n = moveNums(s, n, 1);
        }
        if(n>=0 && n<len && s[n]=='.'){
            ++n;
            if(n <len && s[n]>='0' && s[n]<='9'){
                flag = true;
                n = moveNums(s, n, 1);
            }    
        }
        if(!flag)return false;

        // mi
        if(n>=0 && n<len && (s[n]=='e' || s[n]=='E')){
            ++n;
            if(n>=0 && n<len && (s[n]=='+'||s[n]=='-'))++n;
            if(n==len || s[n]<'0' || s[n]>'9')return false;

            n = moveNums(s, n, 1);

        }
        if(n>=0 && n<len && s[n]==' ')n = moveNums(s, n, 0);

        if(n==len)return true;
        else return false;
    }

    int moveNums(string& s, int n, int part){
        if(n==-1||n==len)return -1;
        int i = n;
        if(s[i]=='+'||s[i]=='-')++i;
        if(part==0){
            for( ; i<len; ++i){
                if(s[i]!=' ')break;
            }
        }else if(part==1){
            for( ; i<len; ++i){
                if(s[i]<'0'||s[i]>'9')break;
            }
        }

        if(i!=n)return i;
        else return -1;
    } 
};

int main()
{  
  
    string s[] = {" ", "e", ".", "    .1 "};
    Solution sol;
    for(int i=0; i<4; ++i)cout<<sol.isNumber(s[i])<<endl;

    system("pause");
    return 0;
}