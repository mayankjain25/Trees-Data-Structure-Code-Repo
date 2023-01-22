class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur=root;
        TreeNode * insertPos;
        if(root==NULL){
            root=new TreeNode(val);
            return root;
        }
        while(cur){
            // if(!cur->left or !cur->right) break;
            if(val>cur->val) {
                insertPos=cur;
                cur=cur->right;
            }
            else {
                insertPos=cur;
                cur=cur->left;
            }
            
        }
        
        TreeNode * newNode = new TreeNode(val);
        
        if(val<insertPos->val) insertPos->left = newNode;
        else insertPos->right=newNode;
        
        return root;
    }
};
