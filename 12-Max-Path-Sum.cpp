class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
     maxSum(root,maxi);
        return maxi;
    }
    
    int maxSum(TreeNode *root, int &maxi){
        if(root==NULL) return 0;
        
        int leftSum = max(0,maxSum(root->left,maxi));
        int rightSum =max(0, maxSum(root->right,maxi));
        maxi=max(maxi,leftSum+rightSum+root->val);
        
        return root->val + max(leftSum, rightSum);
    }
};