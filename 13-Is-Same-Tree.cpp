class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL or q==NULL) return p==q;
        
        return (p->val==q->val) and isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
};
