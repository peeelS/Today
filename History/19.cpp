// 2022/08/17
// 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
// 而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。
// 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 参考书中代码
class Solution {
public:
    bool fun(string& s, string& p, int sIdx, int pIdx){
        if(s.size()==0 && p.size()==0)return true;
        if(p.size()==0)return false;
        if(sIdx==s.size() && pIdx==p.size())return true;
        if(sIdx<s.size() && pIdx==p.size())return false;

        if(pIdx<p.size()-1 && p[pIdx+1]=='*'){
            if(sIdx<s.size() && (p[pIdx]==s[sIdx] || p[pIdx]=='.')){
                return fun(s, p, sIdx+1, pIdx+2) || fun(s, p, sIdx+1, pIdx) || fun(s, p, sIdx, pIdx+2);
            }else{
                return fun(s, p, sIdx, pIdx+2);
            }
        }

        if(sIdx<s.size() && (s[sIdx]==p[pIdx] || p[pIdx]=='.'))
            return fun(s, p, sIdx+1, pIdx+1);

        return false;
    }

    bool isMatch(string s, string p) {
        return fun(s, p, 0, 0);
    }
};

int main()
{  
    string s[5] = {"aa", "aa", "ab", "aab", "mississippi"};
    string p[5] = {"a", "a*", ".*", "c*a*b*", "mis*is*p*."};

    Solution sol;
    for(int i=0; i<5; ++i)cout<<sol.isMatch(s[i], p[i])<<endl;

    system("pause");
    return 0;
}