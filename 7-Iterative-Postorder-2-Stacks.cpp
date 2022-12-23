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
            st2.push(node);
            if(node->left)st1.push(node->left);
            if(node->right)st1.push(node->right);
        }
        // vector<int>ans;
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};