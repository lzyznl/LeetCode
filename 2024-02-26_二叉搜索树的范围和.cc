#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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

void dfs(TreeNode* root,int& count,const int low,const int high){
    if(root==nullptr){
        return;
    }
    if((root->val>=low)&&(root->val<=high)){
        count+=root->val;
        dfs(root->left,count,low,high);
        dfs(root->right,count,low,high);
    }else if(root->val<low){
        dfs(root->right,count,low,high);
    }else if(root->val>high){
        dfs(root->left,count,low,high);
    }
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int count = 0;
    dfs(root,count,low,high);
    return count;
}