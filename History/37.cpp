// 2022/09/05
// 请实现两个函数，分别用来序列化和反序列化二叉树。
// 你需要设计一个算法来实现二叉树的序列化与反序列化。
// 这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        if(root==nullptr)return ret;

        int nowlayer  = 1;
        int nextlayer = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            ret.append(to_string(tmp->val)); ret.append(",");
            nowlayer--;

            if(tmp->left!=nullptr){
                q.push(tmp->left);
                nextlayer++;
            }else{
                ret.append("ln,");
            }

            if(tmp->right!=nullptr){
                q.push(tmp->right);
                nextlayer++;
            }else{
                ret.append("rn,");
            }

            if(nowlayer==0){
                nowlayer = nextlayer;
                nextlayer = 0;
                ret.append("e,");
            }


        }
        
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return nullptr;

        // -1 null  -2 endl
        vector<int> nums;
        int last_idx = -1;
        for(int i=0; i<data.size(); ++i){
            if(data[i]==','){
                string s = data.substr(last_idx+1, i-last_idx-1);
                if(s=="ln"){
                    nums.push_back(-1000);
                }else if(s=="rn"){
                    nums.push_back(-2000);
                }else if(s=="e"){
                    nums.push_back(-3000);
                }else{
                    nums.push_back(atoi(s.c_str()));
                }
                last_idx = i;
            }
        }

        vector<int> layers;
        vector<TreeNode*> nodeList;
        int nodeNum = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==-1000 || nums[i]==-2000)continue;
            if(nums[i]==-3000){
                layers.push_back(nodeNum);
                nodeNum = 0;
                continue;
            }
            nodeNum++;
            TreeNode* _node = new TreeNode(nums[i]);
            nodeList.push_back(_node);
        }
        

        vector<bool> leftNode;
        vector<bool> rightNode;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==-3000)continue;
            if(nums[i]!=-1000 && nums[i]!=-2000){
                if(i+1<nums.size() && nums[i+1]==-1000 && i+2<nums.size() && nums[i+2]==-2000){
                    leftNode.push_back(false);
                    rightNode.push_back(false);
                }else if(i+1<nums.size() && nums[i+1]==-2000){
                    leftNode.push_back(true);
                    rightNode.push_back(false);
                }else if(i+1<nums.size() && nums[i+1]==-1000){
                    leftNode.push_back(false);
                    rightNode.push_back(true);
                }else{
                    leftNode.push_back(true);
                    rightNode.push_back(true);
                }
            }
        }

        int idx = 1;
        for(int i=0; i<nodeList.size(); ++i){
            if(leftNode[i]){
                nodeList[i]->left = nodeList[idx];
                idx++;
            }
            if(rightNode[i]){
                nodeList[i]->right = nodeList[idx];
                idx++;
            }
        }

        return nodeList[0];
    }
};

int main()
{   
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    node1->left = node2; node1->right = node3;
    node3->left = node4; node3->right = node5;

    Codec sol;
    string ret = sol.serialize(node1);
    TreeNode* retNode = sol.deserialize(ret);


    system("pause");
    return 0;
}