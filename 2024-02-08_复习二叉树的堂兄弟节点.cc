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


bool isXorisY(TreeNode* node,int x,int y){
    return (node!=nullptr)&&((node->val==x)||(node->val==y));
}

bool isCousins(TreeNode *root, int x, int y)
{
    if(root->val==x||root->val==y){
        return false;
    }
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int count = 0;
        int size = que.size();
        for(int i=0;i<size;++i){
            TreeNode* node = que.front();
            que.pop();
            if(isXorisY(node->left,x,y)&&isXorisY(node->right,x,y)){
                return false;
            }
            if(isXorisY(node,x,y)){
                count++;
            }
            if(node->left){
                que.push(node->left);
            }
            if(node->right){
                que.push(node->right);
            }
        }
        if(count==1){
            return false;
        }
    }
    return true;
}