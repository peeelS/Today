// 2022/08/24
// 请完成一个函数，输入一个二叉树，该函数输出它的镜像

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)return nullptr;
        TreeNode* head = root;

        TreeNode* tmp_left = root->left;
        TreeNode* tmp_right = root->right;
        root->left = tmp_right;
        root->right = tmp_left;
        if(tmp_left!=nullptr)mirrorTree(tmp_left);
        if(tmp_right!=nullptr)mirrorTree(tmp_right);

        return root;

    }
};


void printTreeDSFS(TreeNode* head){

    queue<TreeNode*> q;
    q.push(head);
    while(q.size()>0){
        TreeNode* tmpN= q.front();
        q.pop();
        cout<<tmpN->val<<" ";
        if(tmpN->left!=nullptr)q.push(tmpN->left);
        if(tmpN->right!=nullptr)q.push(tmpN->right);    
    }
    cout<<endl;
}


int main()
{  
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(9);

    node4->left = node2; node4->right = node7;
    node2->left = node1; node2->right = node3;
    node7->left = node6; node7->right = node9;

    printTreeDSFS(node4);
    Solution sol;
    sol.mirrorTree(node4);
    printTreeDSFS(node4);

    system("pause");
    return 0;
}