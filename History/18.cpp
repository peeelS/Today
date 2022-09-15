// 2022/08/16
// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
// 返回删除后的链表的头节点。
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val){
            head = head->next;
        }else{
            ListNode* pNode = head;
            while(pNode->next!=NULL){
                if(pNode->next->val==val){
                    pNode->next = pNode->next->next;
                    break;
                }
                pNode = pNode->next;
            }
        }

        return head;
    }
};

void showListNode(ListNode* head){
    while(head!=nullptr){
        cout<<head->val<<endl;
        head = head->next;
    }
    cout<<"----------------------"<<endl;
}


int main()
{   
    ListNode* node0 = new ListNode(4);
    ListNode* node1 = new ListNode(5);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(9);
    node0->next = node1; node1->next = node2; node2->next = node3;

    showListNode(node0);

    Solution sol;
    sol.deleteNode(node0, 5);

    showListNode(node0);    
    system("pause");
    return 0;
}