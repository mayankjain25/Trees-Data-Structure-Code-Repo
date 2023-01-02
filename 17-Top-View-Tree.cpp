
//Problem Link: https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0

vector<int> getTopView(TreeNode<int> *root) {
      
     vector<int>ans;
    if(root==NULL) return ans;
    queue<pair<TreeNode<int>*, int>>q; //node - vertical
    map<int,int>m; //vertical - val
    q.push({root, 0});
    while(!q.empty()){
        auto val = q.front();
        q.pop();
        TreeNode<int>*node = val.first;
        int vertical = val.second;
        if(m.find(vertical)==m.end()) m[vertical] = node->val;
        if(node->left){
            q.push({node->left,vertical-1});
        }
        if(node->right) q.push({node->right,vertical+1});
    }
    
    for(auto it:m) ans.push_back(it.second);
    return ans;
        
}
