class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // if(root==NULL) return root;
        while(root!=NULL and root->val!=val){
            root=val<root->val?root->left:root->right;
        }
        
        return root;
    }
    
};
