// 2022/08/25
// 请完成一个函数，输入一个二叉树，该函数输出它的镜像
// 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//         1
//      2     2
//    3  4   4  3
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
    void buildTree(TreeNode* newHead, TreeNode* oldHead){
        if(oldHead==nullptr)return;

        if(oldHead->left!=nullptr){
            newHead->right = new TreeNode(oldHead->left->val);
            buildTree(newHead->right, oldHead->left);
        }
        if(oldHead->right!=nullptr){
            newHead->left = new TreeNode(oldHead->right->val);
            buildTree(newHead->left, oldHead->right);
        }
    }

    bool func(TreeNode* a, TreeNode* b){
        if(a==nullptr && b==nullptr)return true;
        if(a==nullptr && b!=nullptr)return false;
        if(a!=nullptr && b==nullptr)return false;

        if(a->val != b->val)return false;
        else return func(a->left, b->left) && func(a->right, b->right);
    }


    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        TreeNode* newHead = new TreeNode(root->val);
        buildTree(newHead, root);

        return func(newHead, root);
    }   
};




int main()
{   
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2_0 = new TreeNode(2);
    TreeNode* node2_1 = new TreeNode(2);

    TreeNode* node3_0 = new TreeNode(3);
    TreeNode* node4_1 = new TreeNode(4);
    TreeNode* node4_2 = new TreeNode(4);
    TreeNode* node3_3 = new TreeNode(3);

    node1->left = node2_0; node1->right = node2_1;
    node2_0->left = node3_0; node2_0->right = node4_1;
    node2_1->left = node4_1; node2_1->right = node3_3;
    
    Solution sol;
    cout<<sol.isSymmetric(node1)<<endl;

    system("pause");
    return 0;
}