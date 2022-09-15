// 2022/08/28
// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。
// 例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列
// 但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

// 没注意对 标记位 重置，导致对空的stack进行pop，造成错误
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

 
class Solution {
public:
    stack<int> s;

    bool func(vector<int>& pushed, vector<int>& popped, int m, int n){    
        if(n==popped.size())return true;

        bool result = false;
        // push
        if(m < pushed.size()){
            s.push(pushed[m]);
            result = result || func(pushed, popped, m+1, n);
            s.pop();
        } 
        // pop
        if(!s.empty()){
            int value = s.top();
            if(value==popped[n]){
                s.pop();
                result = result || func(pushed, popped, m, n+1);
                s.push(value);
            }
        }
      
        return result;
    }

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {  
        return func(pushed, popped, 0, 0);
    }
};

int main()
{   
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> poped = {4, 5, 3, 2, 1};

    Solution sol;
    cout<<sol.validateStackSequences(pushed, poped)<<endl;

    system("pause");
    return 0;
}