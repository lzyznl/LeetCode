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


/**
 * 个人题解：https://leetcode.cn/problems/diameter-of-binary-tree/solutions/2634179/er-cha-shu-de-zhi-jing-by-elastic-hypati-2it3/
*/
int depth(TreeNode* root,int& ans){
    if(root==nullptr){
        return 0;
    }
    int left_depth = depth(root->left,ans);
    int right_depth = depth(root->right,ans);
    ans = max(ans,left_depth+right_depth);
    return max(left_depth,right_depth)+1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int ans=0;
    depth(root,ans);
    return ans;
}