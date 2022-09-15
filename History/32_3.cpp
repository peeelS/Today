// 2022/08/31
// 请实现一个函数按照之字形顺序打印二叉树
// 即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印
// 第三行再按照从左到右的顺序打印，其他行以此类推。
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class Solution {
public:

    void swapLayer(vector<int>& nums){
        for(int i=0; i<nums.size()/2; ++i){
            int idx = nums.size()-1-i;
            int tmp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tmp;
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr)return ret;

        queue<TreeNode*> qNode; qNode.push(root);
        queue<int> qLayer; qLayer.push(0);
        int nowLayer = 0;
        vector<int> retLayer;

        while(!qNode.empty())
        {
            TreeNode* node = qNode.front(); qNode.pop();
            int layer = qLayer.front(); qLayer.pop();

            if(layer!=nowLayer){
                if((nowLayer&1)==1)swapLayer(retLayer);
                nowLayer = layer;
                ret.push_back(retLayer);
                retLayer.clear();
            }
            retLayer.push_back(node->val);

            if(node->left!=nullptr){
                qNode.push(node->left);
                qLayer.push(layer+1);
            }
            if(node->right!=nullptr){
                qNode.push(node->right);
                qLayer.push(layer+1);
            }
        }

        if((nowLayer&1)==1)swapLayer(retLayer);
        ret.push_back(retLayer);


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
    vector<vector<int>> ret = sol.levelOrder(node3);
    for(int i=0; i<ret.size(); ++i){
        for(int j=0; j<ret[i].size(); ++j){
            cout<<ret[i][j]<<" "; 
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}