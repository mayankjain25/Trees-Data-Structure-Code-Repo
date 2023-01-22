class Solution {
public:  
    bool helper(TreeNode *root,long lower, long higher){
        if(root==NULL) return true;
        if(root->val >=higher or root->val<=lower) return false;
        bool left=helper(root->left,lower,root->val);
        bool right=helper(root->right,root->val,higher);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN,LONG_MAX);
    }
};
