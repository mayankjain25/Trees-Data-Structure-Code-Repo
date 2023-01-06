//Problem: https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int val=0;
        while(!q.empty()){
            int n = q.size();
            
            for(int i=1;i<=n;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node ->right);
                val=node->val;
            }
            ans.push_back(val);
        }
        return ans;
    }
};
