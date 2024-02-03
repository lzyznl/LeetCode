#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> stack;
    vector<int> vt;
    while (root != nullptr || !stack.empty())
    {
        while (root != nullptr)
        {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        vt.push_back(root->val);
        root = root->right;
    }
    return vt;
}

vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> stack;
    vector<int> vt;
    while (root != nullptr || !stack.empty())
    {
        while (root != nullptr)
        {
            vt.push_back(root->val);
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        root = root->right;
    }
    return vt;
}

vector<int> preorderTraversal2(TreeNode *root)
{
    stack<TreeNode *> stack;
    vector<int> vt;
    if (root != nullptr)
    {
        stack.push(root);
    }
    while (!stack.empty())
    {
        TreeNode *node = stack.top();
        vt.push_back(node->val);
        stack.pop();
        if (node->right != nullptr)
        {
            stack.push(node->right);
        }
        if (node->left != nullptr)
        {
            stack.push(node->left);
        }
    }
    return vt;
}

vector<int> postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> stack;
    vector<int> vt;
    if (root != nullptr)
    {
        stack.push(root);
    }
    while (!stack.empty())
    {
        TreeNode *node = stack.top();
        vt.push_back(node->val);
        stack.pop();
        if (node->left != nullptr)
        {
            stack.push(node->left);
        }
        if (node->right != nullptr)
        {
            stack.push(node->right);
        }
    }
    reverse(vt.begin(),vt.end());
    return vt;
}
