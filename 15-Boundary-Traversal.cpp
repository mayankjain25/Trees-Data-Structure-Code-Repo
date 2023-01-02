//Problem Link: https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos

//Approach:
//To print in anticlockwise direction
//First print the left boundary (without the leaf nodes)
//Secondly, print the leaf nodes
//Third, print the right boundary (in reverse order) and this should not include the leaf nodes

bool isLeaf(TreeNode<int> *root){
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode<int> *root, vector<int>&ans){
    TreeNode<int> * cur = root->left;
    
    while(cur){
        if(!isLeaf(cur))  ans.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur=cur->right;
    }
}


void addLeaf(TreeNode<int> * root, vector<int>&ans){
    if(isLeaf(root)) ans.push_back(root->data);
    if(root->left) addLeaf(root->left,ans);
    if(root->right) addLeaf(root->right,ans);
}

void addRight(TreeNode<int> * root, vector<int>&ans){
    TreeNode<int> * cur = root->right;
    vector<int>temp;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur=cur->right;
        else cur=cur->left;
        
    }
    
    for(int i = temp.size()-1;i>=0;i--) ans.push_back(temp[i]);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    
    if(root==NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    
    addLeftBoundary(root,ans);
    addLeaf(root,ans);
    addRight(root,ans);
    return ans;
}
