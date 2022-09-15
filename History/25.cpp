// 2022/08/22
// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr && l2==nullptr)return nullptr;
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;

        ListNode* head;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }

        ListNode* node = head;

        while(l1!=nullptr && l2!=nullptr){
            if(l1->val < l2->val){
                node->next = l1;
                node = l1;
                l1 = l1->next;
            }else{
                node->next = l2;
                node = l2;
                l2 = l2->next;
            }
        }

        if(l1==nullptr)node->next = l2;
        else node->next = l1;

        return head;
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
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node4;
    
    ListNode* node_1 = new ListNode(1);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);

    node_1->next = node_3;
    node_3->next = node_4;


    Solution sol;
    node1 = sol.mergeTwoLists(node1, node_1);
    printList(node1);

    system("pause");
    return 0;
}