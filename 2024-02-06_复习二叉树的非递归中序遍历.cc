#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> vt;
    stack<TreeNode*> stack;
    if(root==nullptr){
        return vt;
    }
    while(root!=nullptr||!stack.empty()){
        while(root!=nullptr){
            stack.push(root);
            root=root->left;
        }
        root = stack.top();
        stack.pop();
        vt.push_back(root->val);
        root=root->right;
    }
    return vt;
}