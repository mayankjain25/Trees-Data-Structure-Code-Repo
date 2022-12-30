//By reversing the temp array
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        
        int index=1;
        
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            
            vector<int>temp;
            
            for(int i=0;i<n;i++){
                TreeNode *node = q.front();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                temp.push_back(node->val);
                q.pop();
            }
            
            if(!(index&1)){
                reverse(temp.begin(),temp.end());
            }
            
            ans.push_back(temp);
            index++;
        }
        
        return ans;
    }
};


//without reversing the temp array

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        bool leftToRight=true;
        int index=1;
        
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            
            vector<int>temp(n);
            
            for(int i=0;i<n;i++){
                TreeNode *node = q.front();
                
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                
                int pushIndex = leftToRight? i: n - i -1;
                temp[pushIndex] = node->val;
                q.pop();
            }
            
          
            
            ans.push_back(temp);
            leftToRight = !leftToRight;
            index++;
        }
        
        return ans;
    }
};


