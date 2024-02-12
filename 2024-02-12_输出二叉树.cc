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


int depth(TreeNode* node){
    if(node==nullptr){
        return 0;
    }
    int left_height=depth(node->left);
    int right_height=depth(node->right);
    return max(left_height,right_height)+1;
}


void dfs(int row,int column,TreeNode* node,vector<vector<string>>& res,const int& height){
    if(node==nullptr){
        return ;
    }
    string val = to_string(node->val);
    res[row][column] = val;
    dfs(row+1,(column-(1<<(height-row-1))),node->left,res,height);
    dfs(row+1,(column+(1<<(height-row-1))),node->right,res,height);
}

vector<vector<string>> printTree(TreeNode *root)
{
    int treeHeight = depth(root);
    int m = treeHeight+1;
    int n = (1<<(treeHeight+1))-1;
    vector<vector<string>> res(n,vector<string>(m,""));
    dfs(0,(n-1)/2,root,res,treeHeight);
    return res;
}