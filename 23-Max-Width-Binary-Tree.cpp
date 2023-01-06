class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int start = q.front().second;
            int last=q.back().second;
            ans=max(ans,last-start+1);
            int n =q.size();
            for(int i=1;i<=n;i++){
                auto p=q.front();
                q.pop();
                TreeNode * node = p.first;
                long long index=p.second-start;
                if(node->left) q.push({node->left,(long long)2*index+1});
                if(node->right) q.push({node->right,(long long)2*index+2});
                
            }
        }
        
        return ans;
    }
};
