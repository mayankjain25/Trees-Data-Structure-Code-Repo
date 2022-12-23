//Preorder - Root Left Right
//https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int>preorder;
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(root==NULL) return {};
        preorder.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return preorder;
    }
};

//Time Complexity - O(N), Auxillaru Space - O(N) for recursion

int main(){
    return 0;
}