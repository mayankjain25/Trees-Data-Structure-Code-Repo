//Problem Link: https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0



vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int>ans;
    map<int,int>m;
    queue<pair<BinaryTreeNode<int>*, int>>q; //node - vertical
    q.push({root,0});
    
    while(!q.empty()){
        BinaryTreeNode<int>*node = q.front().first;
        int vertical = q.front().second;
        q.pop();
        m[vertical] = node->data;
        if(node->left) q.push({node->left, vertical-1});
        if(node->right) q.push({node->right,vertical+1});
    }
    
    for(auto it:m) ans.push_back(it.second);
    return ans;
    
}
