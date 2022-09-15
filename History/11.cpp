#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size()-1;
        while((right-left)>1){
            int mid = (left+right)>>1;
            if(numbers[mid]>numbers[right]) left = mid;
            else right = mid;
        }
        

        return min(numbers[left], numbers[right]);
    }
};

int main()
{
    vector<int> num = {3,4,5,1,2};
    Solution sol;
    cout<<sol.minArray(num)<<endl;

    system("pause");
    return 0;
}