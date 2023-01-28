class Solution {
public:
    
    TreeNode * makeTree(int &ind, vector<int>&preorder, int ub){
        if(ind==preorder.size() or preorder[ind]>ub) return NULL;
        TreeNode * root = new TreeNode(preorder[ind++]);
        root->left = makeTree(ind, preorder, root->val);
        root->right = makeTree(ind, preorder,ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder){
    
       int i=0;
        return makeTree(i,preorder, INT_MAX);
        
    }
    
  
    

};
