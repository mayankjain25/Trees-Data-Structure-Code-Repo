//Problem Link: https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0




/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include<bits/stdc++.h>
BinaryTreeNode<int>* parentMap(BinaryTreeNode<int>*root,unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &parentTrack,int target){
    queue<BinaryTreeNode<int>*>q;
    BinaryTreeNode<int>*res;
    q.push(root);
    
    while(!q.empty()){
        BinaryTreeNode<int>* node =q.front();
        q.pop();
        if(node->data==target) res=node;
        if(node->left){
            parentTrack[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parentTrack[node->right]=node;
            q.push(node->right);
        }
    }
    
    return res;
}



int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parentTrack;
    
//     for(auto it:parentTrack) cout<<it.first->data<<" "<<it.second->data<<endl;
    
    unordered_map<BinaryTreeNode<int>*, bool>visited;
    queue<BinaryTreeNode<int>*>q;
    BinaryTreeNode<int>* temp=   parentMap(root,parentTrack,start);

//     cout<<temp->data;
    visited[temp]=true;
    q.push(temp);
    int ans=-1;
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if(node->left and !visited[node->left]){
                q.push(node->left);
                visited[node->left]=true;
            }
            if(node->right and !visited[node->right]){
                q.push(node->right);
                visited[node->right]=true;
            }
            if(parentTrack[node] and !visited[parentTrack[node]]){
                q.push(parentTrack[node]);
                visited[parentTrack[node]]=true;
            }
        }
                ans++;

    }
//     cout<<endl<<"--------"<<endl;
    return ans;
}
