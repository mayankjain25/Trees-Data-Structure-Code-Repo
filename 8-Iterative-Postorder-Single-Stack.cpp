class Solution {
public:
    // vector<int>postorder;
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st1,st2;
        vector<int>ans;
        if(root==NULL) return ans;
        st1.push(root);
        while(!st1.empty()){
            TreeNode *node=st1.top();
            st1.pop();
            ans.push_back(node->val);
            if(node->left)st1.push(node->left);
            if(node->right)st1.push(node->right);
        }
        // vector<int>ans;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};