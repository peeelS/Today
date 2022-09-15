// 2022/08/30
// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr)return ret;
        queue<TreeNode*> qNode;
        queue<int> qLayer;
        qNode.push(root);
        qLayer.push(0);
        int nowLayer = 0;
        
        vector<int> retLayer;
        while(!qNode.empty())
        {
            TreeNode* topNode = qNode.front();
            qNode.pop();
            int nodeLayer = qLayer.front();
            qLayer.pop();
            if(nodeLayer!=nowLayer){
                nowLayer = nodeLayer;
                ret.push_back(retLayer);
                retLayer.clear();
            }
            retLayer.push_back(topNode->val);
                


            if(topNode->left!=nullptr){
                qNode.push(topNode->left);
                qLayer.push(nodeLayer+1);
            }
            if(topNode->right!=nullptr){
                qNode.push(topNode->right);
                qLayer.push(nodeLayer+1);
            }

        }
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


    vector<vector<int>> tmp;
    
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