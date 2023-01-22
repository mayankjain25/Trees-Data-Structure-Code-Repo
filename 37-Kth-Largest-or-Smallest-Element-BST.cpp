class Solution {
    void inorderTraversal(TreeNode*root, vector<int>&inorder){
        if(root==NULL) return;
        
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        inorderTraversal(root,inorder);
        return inorder[k-1];
    }
};
