// 2022/09/04
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
// 要求不能创建任何新的节点，只能调整树中节点指针的指向。

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
    Node* left;
    Node* right;
    
    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void func(Node* root, vector<Node*> &nums){
        if(root->left==nullptr && root->right==nullptr){
            nums.push_back(root);
            return;
        }
        if(root->left!=nullptr)func(root->left, nums);
        nums.push_back(root);
        if(root->right!=nullptr)func(root->right, nums);
    }

    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)return root;

        vector<Node*> nums;
        func(root, nums);
        
        int len = nums.size();
        for(int i=0; i<len; ++i){
            nums[i]->right = nums[(i+1)%len];
            nums[i]->left = nums[(i+len-1)%len]; 
        }

        return nums[0];
    }
};


int main()
{   
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node4->left = node2; node4->right = node5;
    node2->left = node1; node2->right = node3;

    Solution sol;
    sol.treeToDoublyList(node4);

    system("pause");
    return 0;
}