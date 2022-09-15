// 2022/08/29
// 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印
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
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ret;
        if(root==nullptr)return ret;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ret.push_back(node->val);

            if(node->left!=nullptr)q.push(node->left);
            if(node->right!=nullptr)q.push(node->right);
        }

        return ret;
    }
};

int main()
{   
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20);
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);
    
    node3->left = node9; node3->right = node20;
    node20->left = node15; node20->right = node7;

    Solution sol;
    vector<int> ret = sol.levelOrder(node3);
    
    for(int i=0; i<ret.size(); ++i)cout<<ret[i]<<endl;

    system("pause");
    return 0;
}