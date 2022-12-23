class Solution {
private:
    int findHeight(TreeNode * root, int &diameter){
        if(root==NULL) return 0;
        int leftHeight = findHeight(root->left, diameter);
        int rightHeight = findHeight(root->right, diameter);
        diameter = max(diameter, leftHeight+rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        findHeight(root,diameter);
        return diameter;
    }
};