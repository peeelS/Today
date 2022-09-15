// 2022/08/21
// 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode = nullptr;
        ListNode* nowNode = head;
        while(nowNode!=nullptr){
            ListNode* nextNode = nowNode->next;
            nowNode->next = preNode;
            preNode = nowNode;
            nowNode = nextNode;
        }
        return preNode;
    }
};


void printList(ListNode* head){
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next; 
    }
    cout<<endl;
}

int main()
{  
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    printList(node1);
    Solution sol;
    node1 = sol.reverseList(node1);
    
    cout<<"-------------------"<<endl;
    printList(node1);

    system("pause");
    return 0;
}