// 2022/09/03
// 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return head;
        vector<Node*> nodeList;
        Node* tmpHead = head;
        while(tmpHead!=nullptr){
            nodeList.push_back(tmpHead);
            tmpHead = tmpHead->next;
        }

        vector<int> randomIdx;
        while(head!=nullptr){
            Node* tmpRandom = head->random;
            if(tmpRandom==nullptr){
                randomIdx.push_back(-1);
            }else{
                for(int i=0; i<nodeList.size(); ++i){
                    if(nodeList[i]==tmpRandom){
                        randomIdx.push_back(i);
                        break;
                    }
                }
            }
            head = head->next;
        }


        vector<Node*> retNodeList;
        for(int i=0; i<nodeList.size(); ++i){
            int value = nodeList[i]->val;
            Node* node = new Node(value);
            retNodeList.push_back(node);
        }

        for(int i=0; i<retNodeList.size(); ++i){
            if(i<retNodeList.size()-1){
                retNodeList[i]->next = retNodeList[i+1];
            }

            int idx = randomIdx[i];
            if(idx!=-1){
                retNodeList[i]->random = retNodeList[idx];
            }
        }

        return retNodeList[0];
    }
};

int main()
{   
    Node* node3_0 = new Node(3);
    Node* node3_1 = new Node(3);
    Node* node3_2 = new Node(3);

    node3_0->next = node3_1; node3_1->next = node3_2;

    node3_1->random = node3_0;

    Solution sol;
    Node* ret = sol.copyRandomList(node3_0);

    system("pause");
    return 0;
}