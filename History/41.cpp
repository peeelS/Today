// 2022/09/09 时间占用极大 
// 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
// 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
// 例如，
// [2,3,4] 的中位数是 3
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5
// 设计一个支持以下两种操作的数据结构：
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。
// double findMedian() - 返回目前所有元素的中位数。


#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct MyListNode
{
    int val;
    MyListNode* next;
    MyListNode(int x):val(x), next(nullptr){}
};



class MedianFinder {
public:
    MyListNode* head = nullptr;
    int len = 0;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        len++;
        if(head==nullptr){
            head = new MyListNode(num);
            return ;
        }else{
            MyListNode* node = head;
            MyListNode* newNum = new MyListNode(num);

            if(num < head->val){
                newNum->next = head;
                head = newNum;
                return;
            }

            while (node ->next != nullptr)
            {
                if(node->val <= num && node->next->val >= num){
                    newNum->next = node->next;
                    node->next = newNum;
                    return;
                }
                node = node->next;
            }
            
            node->next = newNum;
        }
    }
    
    double findMedian() {
        if(len==1)return head->val;

        MyListNode* node = head;
        double ret = 0;
        int i = 1;
        int targetIdx = int(len/2);
        while (i<len+1)
        {      
            if(i==targetIdx){
                if(len%2 == 0){
                    ret = (node->val*1.0 + node->next->val*1.0)/2.0;
                }else{
                    ret = node->next->val;
                }

                break;
            }
            node = node->next;
            ++i;
        }
        
        return ret;

    }
};


int main()
{   
    MedianFinder* obj = new MedianFinder();

    obj->addNum(-1); 
    cout<<obj->findMedian()<<endl;

    obj->addNum(-2);
    cout<<obj->findMedian()<<endl;

     obj->addNum(-3);
    cout<<obj->findMedian()<<endl;

     obj->addNum(-4);
    cout<<obj->findMedian()<<endl;

     obj->addNum(-5);
    cout<<obj->findMedian()<<endl;


    system("pause");
    return 0;
}