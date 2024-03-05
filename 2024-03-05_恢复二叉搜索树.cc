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

vector<int> midOrderNum;
int size = 0;
vector<int> faultNum;

void midOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    midOrder(root->left);
    midOrderNum.push_back(root->val);
    midOrder(root->right);
}

void findFaultNum(){
    for(int i=0;i<midOrderNum.size()-1;++i){
        if(midOrderNum[i]>midOrderNum[i+1]){
            size++;
        }
    }
    for(int i=0;i<midOrderNum.size()-1;++i){
        if(midOrderNum[i]>midOrderNum[i+1]){
            if(size==1){
                faultNum.push_back(midOrderNum[i]);
                faultNum.push_back(midOrderNum[i+1]);
            }else if(size==2){
                if(faultNum.empty()){
                    faultNum.push_back(midOrderNum[i]);
                }else{
                    faultNum.push_back(midOrderNum[i+1]);
                }
            }
        }
    }
}

void dfs(TreeNode* root){
    if(root==nullptr){
        return;
    }
    dfs(root->left);
    if(root->val==faultNum[0]){
        root->val=faultNum[1];
    }else if(root->val==faultNum[1]){
        root->val=faultNum[0];
    }
    dfs(root->right);
}

void recoverTree(TreeNode *root)
{
    midOrder(root);
    findFaultNum();
    dfs(root);
}