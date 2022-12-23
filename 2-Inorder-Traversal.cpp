//Left Root Right
// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/


class Solution {
public:
    vector<int>inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
        return inorder;
    }
};