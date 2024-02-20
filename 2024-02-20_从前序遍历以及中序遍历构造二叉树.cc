#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

unordered_map<int,int> map;

TreeNode* DFSBuildTree(const vector<int>& preorder,const vector<int>& inorder,
                    int preorder_left,int preorder_right,int inorder_left,int inorder_right){
            if(preorder_left>preorder_right){
                return nullptr;
            }
            int preorder_root=preorder[preorder_left];    
            int inorder_root_index = map[preorder_root];
            int size_left_subTree = inorder_root_index-inorder_left;
            //创建当前节点
            TreeNode* root = new TreeNode(preorder_root);
            root->left=DFSBuildTree(preorder,inorder,preorder_left+1,preorder_left+size_left_subTree,inorder_left,inorder_root_index-1);
            root->right=DFSBuildTree(preorder,inorder,preorder_left+size_left_subTree+1,preorder_right,inorder_root_index+1,inorder_right);
            return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    //建立对中序遍历的哈希索引
    int size = inorder.size();
    for(int i=0;i<size;++i){
        map[inorder[i]]=i;
    }
    return DFSBuildTree(preorder,inorder,0,size-1,0,size-1);
}