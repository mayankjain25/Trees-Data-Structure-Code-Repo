//https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1


int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil=-1;
    if(node==NULL) return -1;
    while(node){
        if(node->data==x) {
            ceil=node->data;
            return ceil;
        }
        else if(node->data > x){
            ceil=node->data;
            node=node->left;
        }
        else if(node->data < x){
            node=node->right;
        }
    }
    
    return ceil;
}
