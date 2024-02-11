#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
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

vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode*> stack;
    vector<int> vt;
    if(root==nullptr){
        return vt;
    }
    stack.push(root);
    while(!stack.empty()){
        TreeNode* node = stack.top();
        stack.pop();
        vt.push_back(node->val);
        if(node->right){
            stack.push(node->right);
        }
        if(node->left){
            stack.push(node->left);
        }
    }
    return vt;
}

vector<int> postorderTraversal(TreeNode *root)
{
    //根左右->根右左->左根右
    stack<TreeNode*> stack;
    vector<int> vt;
    if(root==nullptr){
        return vt;
    }
    stack.push(root);
    while(!stack.empty()){
        TreeNode* node = stack.top();
        stack.pop();
        vt.push_back(node->val);
        if(node->left){
            stack.push(node->left);
        }
        if(node->right){
            stack.push(node->right);
        }
    }
    reverse(vt.begin(),vt.end());
    return vt;
}


vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> vt;
    stack<TreeNode*> stack;
    if(root==nullptr){
        return vt;
    }
    while(root!=nullptr||!stack.empty()){
        while(root){
            stack.push(root);
            root=root->left;
        }
        root=stack.top();
        stack.pop();
        vt.push_back(root->val);
        root=root->right;
    }
    return vt;
}