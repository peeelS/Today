// 2022/08/19
// 书中 面试题8
// 给定一颗二叉树和其中的一个节点，如何找出中序遍历序列的下一个节点？
// 树中的节点除了有两个分别指向左、右子节点的指针，还有一个指向父节点的指针
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(char x):val(x), left(nullptr), right(nullptr), parent(nullptr){} 
};


class Solution{
public:
    TreeNode* findNextNode(TreeNode* node, bool rightFlag){
        if(node==nullptr)return nullptr;
        // 存在右子树 且 右子树尚未遍历过
        if((!rightFlag) && node->right!=nullptr){
            node = node->right;
            while(node->left!=nullptr){
                node = node->left;
            }
        }else{
            // 不存在父节点
            if(node->parent==nullptr)return nullptr;
            // 是父节点的左节点
            TreeNode* parentNode = node->parent;
            if(parentNode->left==node)return parentNode;
            // 是父节点的右节点
            node = findNextNode(parentNode, true);     
        }    

        return node;
    }

};

int main()
{  
    
    TreeNode* a = new TreeNode('a');
    TreeNode* b = new TreeNode('b');
    TreeNode* c = new TreeNode('c');
    TreeNode* d = new TreeNode('d');
    TreeNode* e = new TreeNode('e');
    TreeNode* f = new TreeNode('f');
    TreeNode* g = new TreeNode('g');
    TreeNode* h = new TreeNode('h');
    TreeNode* i = new TreeNode('i');

    a->left = b; a->right = c;
    b->left = d; b->right = e; b->parent = a;
    c->left = f; c->right = g; c->parent = a;
    d->parent = b;
    e->left = h; e->right = i; e->parent = b;
    f->parent = c;
    g->parent = c;
    h->parent = e;
    i->parent = e;

    Solution sol;
    TreeNode* ret;
    ret = sol.findNextNode(d, false);
    if(ret==nullptr)cout<<"last node"<<endl;
    else cout<<ret->val<<endl;

    system("pause");
    return 0;
}