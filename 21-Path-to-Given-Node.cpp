//Problem: https://www.interviewbit.com/problems/path-to-given-node/

bool getPath(TreeNode*node, vector<int>&path, int B){
    if(node==NULL) return false;
    path.push_back(node->val);
        if(node->val==B) return true;
    if(getPath(node->left,path,B) or getPath(node->right,path,B)) return true;
    path.pop_back();
    
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>path;
    if(A==NULL) return path;
    getPath(A,path,B);
    return path;
}
