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
 * 个人题解：https://leetcode.cn/problems/cousins-in-binary-tree-ii/solutions/2634648/er-cha-shu-de-tang-xiong-di-jie-dian-ii-k8hka/
*/
TreeNode *replaceValueInTree(TreeNode *root)
{
    if(root==nullptr){
        return root;
    }
    root->val=0;
    vector<TreeNode*> vt;
    vt.push_back(root);
    while(!vt.empty()){
        vector<TreeNode*> tempVt;
        int nextLevelNum=0;
        //获取到下一层的所有节点之和
        for(auto node:vt){
            if(node->left){
                tempVt.push_back(node->left);
                nextLevelNum+=node->left->val;
            }
            if(node->right){
                tempVt.push_back(node->right);
                nextLevelNum+=node->right->val;
            }
        }
        //更新下一层所有节点的值
        for(auto node:vt){
            int brotherNodeSum = 0;
            int left_num = node->left==nullptr?0:node->left->val;
            int right_num = node->right==nullptr?0:node->right->val;
            brotherNodeSum=left_num+right_num;
            if(node->left){
                node->left->val=nextLevelNum-brotherNodeSum;
            }
            if(node->right){
                node->right->val=nextLevelNum-brotherNodeSum;
            }
        }
        vt=move(tempVt);
    }
    return root;
}