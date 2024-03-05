#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <cmath>
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


bool dfs(TreeNode* root,long long low,long long high){
    if(root==nullptr){
        return true;
    }
    if(root->val<=low||root->val>=high){
        return false;
    }
    return dfs(root->left,low,root->val)&&dfs(root->right,root->val,high);
}

bool isValidBST(TreeNode *root)
{
    return dfs(root,LONG_MIN,LONG_MAX);
}