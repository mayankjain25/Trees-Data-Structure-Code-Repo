
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode *>q;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        
        
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode *ptr=q.front();
                if(ptr->left!=NULL) q.push(ptr->left);
                if(ptr->right!=NULL) q.push(ptr->right);
                temp.push_back(ptr->val);
                
                q.pop();
                
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};