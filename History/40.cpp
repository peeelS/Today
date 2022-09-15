// 2022/09/08
// 输入整数数组 arr ，找出其中最小的 k 个数。
// 例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int book[20000] = {0};
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ret;
        if(k==0)return ret;
        for(int i=0; i<arr.size(); ++i)book[arr[i]]++;
        for(int i=0; i<20000; ++i){
            if(k<=0)break;
            if(book[i]>0){
                for(int j=0; j<min(k, book[i]); ++j)ret.push_back(i);
                k = k-book[i];
            }
        }

        return ret;
    }
};

int main()
{   
    vector<int> arr= {3, 2, 1};
    Solution sol;
    vector<int> ret = sol.getLeastNumbers(arr, 2);
    for(int i=0; i<ret.size(); ++i)cout<<ret[i]<<" ";

    system("pause");
    return 0;
}