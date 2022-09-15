// 2022/09/02
// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，
// 找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
// 叶子节点 是指没有子节点的节点。


#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};


class Solution {
public:
    vector<vector<int>> ret;
    int targetSum = 0;

    void func(TreeNode* root, int nowSum, vector<int>& nums){
        if(root->left==nullptr && root->right == nullptr){
            if(nowSum==targetSum)ret.push_back(nums);
            return;
        }

        if(root->left!=nullptr){
            nums.push_back(root->left->val);
            func(root->left, nowSum+root->left->val, nums);
            nums.pop_back();
        }
        if(root->right!=nullptr){
            nums.push_back(root->right->val);
            func(root->right, nowSum+root->right->val, nums);
            nums.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        targetSum = target;
        if(root==nullptr)return ret;
        vector<int> nums;
        nums.push_back(root->val);
        func(root, root->val, nums);

        return ret; 
    }
};

int main()
{   

    TreeNode* node5 = new TreeNode(5);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node11 = new TreeNode(11);
    TreeNode* node13 = new TreeNode(13);
    TreeNode* node4_1 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node5_1 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    
    node5->left = node4; node5->right = node8;
    node4->left = node11;
    node8->left = node13; node8->right = node4_1;
    node11->left = node7; node11->right = node2;
    node4_1->left = node5_1; node4_1->right = node1;


    Solution sol;
    vector<vector<int>> ret = sol.pathSum(node5, 22);

    for(int i=0; i<ret.size(); ++i){
        for(int j=0; j<ret[i].size(); ++j){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}