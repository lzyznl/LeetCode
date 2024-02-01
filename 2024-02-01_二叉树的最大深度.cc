class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        return max(left_max,right_max)+1;
    }
    

    //遍历树，遍历到一个节点就+1，同步更新最大值
    void find(TreeNode* root,int num,int& ans){
        if(root==nullptr){
            return ;
        }
        num+=1;
        ans = max(ans,num);
        find(root->left,num,ans);
        find(root->right,num,ans);
    }
    int maxDepth1(TreeNode* root) {
        int ans =0;
        find(root,0,ans);
        return ans;
    }
};

