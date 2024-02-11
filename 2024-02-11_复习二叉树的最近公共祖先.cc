#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>
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
unordered_map<int,bool> isVisited;
void dfs(TreeNode* root){
    if(root==nullptr){
        return ;
    }
    if(root->left){
        parentNodeMap[root->left->val]=root;
    }
    if(root->right){
        parentNodeMap[root->right->val]=root;
    }
    dfs(root->left);
    dfs(root->right);
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root==nullptr){
        return nullptr;
    }
    if(root==q){
        return q;
    }
    if(root==p){
        return p;
    }
    parentNodeMap[root->val]=nullptr;
    dfs(root);
    while(p){
        isVisited[p->val]=true;
        p=parentNodeMap[p->val];
    }
    while(q){
        if(isVisited[q->val]){
            return q;
        }
        q=parentNodeMap[q->val];
    }
    return nullptr;
}