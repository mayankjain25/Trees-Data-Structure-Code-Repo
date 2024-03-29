class Solution {
public:
    vector<int>inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>ans;
        TreeNode *node = root;
        // s.push(node);
        while(true){
            if(node!=NULL){
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty()) break;
                node=s.top();
                ans.push_back(node->val);
                node=node->right;
                s.pop();
            }
        }
        return ans;
    }
};