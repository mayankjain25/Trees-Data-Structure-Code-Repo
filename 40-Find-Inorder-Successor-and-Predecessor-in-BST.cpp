//https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

void findSuc(Node *root,Node* &suc,int key){
    if(root==NULL) return;
    
    if(root->key > key){
        suc=root;
        findSuc(root->left,suc,key);
    }
    
    if(root->key<=key){
        findSuc(root->right,suc,key);
    }
}

void findPre(Node *root, Node* &pre, int key){
    if(root==NULL) return;
    if(root->key>=key) findPre(root->left,pre,key);
    if(root->key < key){
        pre=root;
        findPre(root->right,pre,key);
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
pre=NULL;
suc=NULL;
Node * curr=root;
findSuc(root,suc,key);
findPre(curr,pre,key);

}
