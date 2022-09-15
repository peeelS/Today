// 2022/08/20
// 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
// 例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

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
    stack<ListNode*> nums;
    ListNode* getKthFromEnd(ListNode* head, int k) {
        while(head!=nullptr){
            nums.push(head);
            head = head->next;
        }
        if(k>nums.size())return nullptr;

        --k;
        while (k--)nums.pop();

        return nums.top();
    }
};


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

    Solution sol;
    for(int i=1; i<=5; ++i)cout<<sol.getKthFromEnd(node1, i)->val<<endl;

    system("pause");
    return 0;
}