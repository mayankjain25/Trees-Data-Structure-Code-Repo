class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val or root->val==q->val) return root;
        if(root->left==NULL and root->right==NULL) return NULL;
        
        TreeNode* left=NULL,*right=NULL;
        
        if(root->left){
            left=lowestCommonAncestor(root->left,p,q);
        }
        if(root->right){
            right=lowestCommonAncestor(root->right,p,q);
        }
        if(left!=NULL and right!=NULL) return root;
        
        return left==NULL?right:left;
    }
};
