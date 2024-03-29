class Solution {
public:
    vector<int>postorder;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        postorder.push_back(root->val);
        return postorder;
    }
};