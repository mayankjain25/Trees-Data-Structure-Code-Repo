class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int curr = root->val;
        if(curr<p->val and curr<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>p->val and curr>q->val) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};

//TC - O(H), H = height of tree
