// 2022/09/01
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
// 如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool func(vector<int>& nums, int startIdx, int len){
        if(len==0||len==1)return true;

        int endIdx = startIdx+len-1;
        int root_value = nums[endIdx];

        bool result = false;
        for(int i=0; i<=len-1; ++i){
            int leftLen = i;
            int rightLen = len-1-i;
            
            if(leftLen!=0){
                int j=startIdx;
                bool flag = false;
                for(; j<startIdx+leftLen; ++j){
                    if(nums[j]>=root_value)flag=true;
                }
                if(flag)continue;
            }
            if(rightLen!=0){
                int j=startIdx+leftLen;
                bool flag =false;
                for(; j<startIdx+len-1; ++j){
                    if(nums[j]<=root_value)flag=true;
                }
                if(flag)continue;
            }
           
            result = result || (func(nums, startIdx, leftLen) && func(nums, startIdx+leftLen, rightLen));  
        }

        return result;
    }

    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty())return true;
        return func(postorder, 0, postorder.size());
    }
};

int main()
{   

    vector<int> postorder1 = {1, 3, 2, 6, 5};

    Solution sol;
    cout<<sol.verifyPostorder(postorder1)<<endl;


    system("pause");
    return 0;
}