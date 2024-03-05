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



TreeNode *deleteNode(TreeNode *root, int key)
{
    if(!root){
        return nullptr;
    }
    if(root->val>key){
        root->left=deleteNode(root->left,key);
        return root;
    }
    if(root->val<key){
        root->right=deleteNode(root->right,key);
        return root;
    }
    if(root->val==key){
        if(!root->right){
            return root->left;
        }
        if(!root->left){
            return root->right;
        }
        TreeNode* successor = root->right;
        while(successor->left){
            successor=successor->left;
        }
        root->right=deleteNode(root->right,successor->val);
        successor->right=root->right;
        successor->left=root->left;
        return successor;
    }
    return root;
}