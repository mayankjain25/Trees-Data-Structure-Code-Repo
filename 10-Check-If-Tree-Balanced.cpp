//A tree is balanced if the difference in height between a node's left subtree and right subtree is less than or equal to 1 for every node in the tree.



class Solution {
private:
    int findHeight(TreeNode *root){
        if(root==NULL) return 0;
        
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        if(leftHeight == -1 or rightHeight == -1) return -1;
        if(abs(leftHeight - rightHeight)>1) return  -1;
        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return findHeight(root)!=-1;
    }
};