class Solution {
public:
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left_height = height(root->left);
        if(left_height==-1){
            return -1;
        }
        int right_height = height(root->right);
        if(right_height==-1||abs(right_height-left_height)>1){
            return -1;
        }
        return max(left_height,right_height)+1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};