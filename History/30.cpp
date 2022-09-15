// 2022/08/27
// 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中
// 调用 min、push 及 pop 的时间复杂度都是 O(1)。
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


struct MyListNode{
    int val;
    int minValue;
    MyListNode* next;
    MyListNode(int x, int y):val(x), minValue(y), next(NULL){}
};

class MinStack {
public:
    MyListNode* head = NULL;
    MinStack() {}
    
    void push(int x) {
        if(head==NULL){
            head = new MyListNode(x, x);
            return;
        }
        int minValue = head->minValue < x? head->minValue: x;
        MyListNode* node = new MyListNode(x, minValue);
        node->next = head;
        head = node;
    }
    
    void pop() {
        if(head==NULL)return;
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int min() {
        return head->minValue;
    }
};

int main()
{   
    MinStack stack1;
    stack1.push(1); cout<<stack1.top()<<endl;
    stack1.push(-2); cout<<stack1.top()<<endl;
    stack1.push(-3); cout<<stack1.top()<<endl;
    stack1.pop(); cout<<stack1.top()<<endl;

    system("pause");
    return 0;
}