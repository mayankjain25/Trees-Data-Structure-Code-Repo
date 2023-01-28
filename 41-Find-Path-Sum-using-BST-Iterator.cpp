class BSTIterator{
    stack<TreeNode*> st;
    bool reverse=true;
    public:
        BSTIterator(TreeNode *root, bool isReverse){
            reverse=isReverse;
            pushAll(root);
        }
        
        void pushAll(TreeNode * root){
            for(;root!=NULL;){
                st.push(root);
                if(reverse){
                    root=root->right;
                }
                else root=root->left;
            }
        }
    
        bool hasNext(TreeNode *root){
            return !st.empty();
        }
        
        int next(){
            TreeNode *temp = st.top();
            st.pop();
            if(!reverse) pushAll(temp->right);
            else pushAll(temp->left);
            return temp->val;
        }

    
};



class Solution {

public:
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i=l.next(),j=r.next();
        
        while(i<j){
            if((i+j)==k) return true;
            else{
                if((i+j)<k){
                    i=l.next();
                    
                }
                else j = r.next();
            }
        }
        
        return false;
    }
};
