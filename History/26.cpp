// 2022/08/23
// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。
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
    queue<TreeNode*> q;
    // Recursion
    bool func(TreeNode* A, TreeNode* B){
        if(B->left==nullptr && B->right==nullptr)return true;

        bool left_flag = true;
        if(B->left!=nullptr){
            if(A->left==nullptr || A->left->val!=B->left->val){
                left_flag = false;
            }else{
                left_flag = func(A->left, B->left);
            }
        }

        bool right_flag = true;
        if(B->right!=nullptr){
            if(A->right==nullptr || A->right->val!=B->right->val){
                right_flag = false;
            }else{
                right_flag = func(A->right, B->right);
            }
        }

        return left_flag && right_flag;

    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==nullptr)return false;

        int val_B = B->val;
        bool result = false;
        
        q.push(A);
        while (!q.empty())
        {   
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left!=nullptr)q.push(tmp->left);
            if(tmp->right!=nullptr)q.push(tmp->right);

            if(tmp->val==val_B)result += func(tmp, B);
        }
        

        return result;
    }
};

int main()
{  
    TreeNode* A_node1 = new TreeNode(1);
    TreeNode* A_node2 = new TreeNode(2);
    TreeNode* A_node3 = new TreeNode(3);
    TreeNode* A_node4 = new TreeNode(4);
    TreeNode* A_node5 = new TreeNode(5);

    A_node3->left = A_node4; A_node3->right = A_node5;
    A_node4->left = A_node1; A_node4->right = A_node2;

    TreeNode* B_node1 = new TreeNode(1);
    TreeNode* B_node4 = new TreeNode(4);

    B_node4->left = B_node1;

    Solution sol;
    cout<<sol.isSubStructure(A_node3, B_node4)<<endl;

    system("pause");
    return 0;
}