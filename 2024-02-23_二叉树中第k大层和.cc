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

//BFS+排序
long long kthLargestLevelSum(TreeNode *root, int k)
{
    queue<TreeNode*> que;
    vector<long long> vt;
    if(root==nullptr){
        return -1;
    }
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        long long levelCount = 0;
        for(int i=0;i<size;++i){
            TreeNode* node = que.front();
            que.pop();
            if(node->left){
                que.push(node->left);
            }
            if(node->right){
                que.push(node->right);
            }
            levelCount+=node->val;
        }
        vt.push_back(levelCount);
    }
    sort(vt.begin(),vt.end());
    if(vt.size()<k){
        return -1;
    }
    else{
        return vt[vt.size()-k];
    }
}
