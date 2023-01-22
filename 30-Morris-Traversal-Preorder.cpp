class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        if(root==NULL) return preorder;
        
        TreeNode * cur=root;
        
        while(cur!=NULL){
            if(cur->left==NULL){
                preorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode * prev=cur->left;
                while(prev->right and prev->right!=cur) prev=prev->right;
                if(prev->right==NULL){
                    prev->right=cur;
                    preorder.push_back(cur->val);
                    cur=cur->left;
                }          
                else{
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        
        return preorder;
    }
};

