#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int,TreeNode*> parentNodeMap;
unordered_map<int,bool> isvisited;

void dfs(TreeNode* root){
    if(root==nullptr){
        return;
    }
    if(root->left){
        parentNodeMap[root->left->val]=root;
        dfs(root->left);
    }
    if(root->right){
        parentNodeMap[root->right->val]=root;
        dfs(root->right);
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root==nullptr){
        return root;
    }
    dfs(root);
    while(p!=nullptr){
        isvisited[p->val]=true;
        p=parentNodeMap[p->val];
    }
    while(q!=nullptr){
        if(isvisited[q->val]==true){
            return q;
        }
        q=parentNodeMap[q->val];
    }
    return nullptr;
}