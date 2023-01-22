class Solution {
TreeNode *prev=NULL;
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
        
    }
};

//method 2

class Solution {
TreeNode *prev=NULL;
public:
    void flatten(TreeNode* root) {
       TreeNode * now=root;
        
        while(now){
            if(now->left){
                TreeNode * prev = now->left;
                while(prev->right) prev=prev->right;
                prev->right=now->right;
                now->right=now->left;
                now->left=NULL;
            }
            now=now->right;
        }
    }
};

//method 3
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
TreeNode *prev=NULL;
public:
    void flatten(TreeNode* root) {
       stack<TreeNode*>st;
        
        if(root==NULL) return;
        st.push(root);
        
    
        
        while(!st.empty()){
            TreeNode * node = st.top();
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            if(!st.empty()) node->right=st.top();
            node->left=NULL;
        }
    }
};
