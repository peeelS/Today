// 2022.08.08
// 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):value(x), left(nullptr), right(nullptr){}
};


class Solution {
public:
    
    TreeNode* buildCore(vector<int>& preorder, int i, vector<int>& inorder, int j, int len){
        if(len<1)return nullptr;
        TreeNode* root = new TreeNode(preorder[i]);
        int idx;
        for(idx=j; idx<j+len; ++idx)
            if(inorder[idx]==preorder[i])break;
        
        root->left = buildCore(preorder, i+1, inorder, j, idx-j);
        root->right = buildCore(preorder, i+1+idx-j, inorder, idx+1, len-(idx-j)-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildCore(preorder, 0, inorder, 0, preorder.size());
    }
};

void ShowTreeNum(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()>0){
        TreeNode* tmpNode = q.front();
        q.pop();
        cout<<tmpNode->value<<" ";
        if(tmpNode->left!=nullptr)q.push(tmpNode->left);
        if(tmpNode->right!=nullptr)q.push(tmpNode->right);
    }
}


int main()
{       
    vector<int> p = {3, 9, 20, 15, 7};
    vector<int> i = {9, 3, 15, 20, 7};
    Solution sol;
    TreeNode* pTree = sol.buildTree(p, i);

    ShowTreeNum(pTree);

    system("pause");
    return 0;
}