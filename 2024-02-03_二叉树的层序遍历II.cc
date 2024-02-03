#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vt;
        if(root==nullptr){
            return vt;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> innerVt;
            for(int i=0;i<size;++i){
                TreeNode* node = que.front();
                innerVt.push_back(node->val);
                if(node->left!=nullptr){
                    que.push(node->left);
                }
                if(node->right!=nullptr){
                    que.push(node->right);
                }
                que.pop();
            }
            vt.push_back(innerVt);
        }
        reverse(vt.begin(),vt.end());
        return vt;
}