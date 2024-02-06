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
 * 个人题解:https://leetcode.cn/problems/invert-binary-tree/solutions/2634150/fan-zhuan-er-cha-shu-by-elastic-hypatiad-0x9p/
*/
void reverseTree(TreeNode* root){
    if(root==nullptr){
        return ;
    }
    TreeNode* node = root->left;
    root->left=root->right;
    root->right=node;
    reverseTree(root->left);
    reverseTree(root->right);
}

TreeNode *invertTree(TreeNode *root)
{
    TreeNode* head = root;
    reverseTree(root);
    return head;
}