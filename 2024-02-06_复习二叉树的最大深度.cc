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


int findMax(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int left_height = findMax(root->left);
    int right_height = findMax(root->right);
    return max(left_height,right_height)+1;
}

/**
 * 类似于二叉树的前序遍历，维护一个全局变量，在遍历过程中不断更新这个全局变量的最大值
*/
void findMax2(TreeNode* root,int num,int& ans){
    if(root==nullptr){
        return ;
    }
    num+=1;
    ans = max(ans,num);
    findMax2(root->left,num,ans);
    findMax2(root->right,num,ans);
}

int maxDepth(TreeNode *root)
{
    int ans = 0;
    findMax2(root,0,ans);
    return ans;
}