//https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1

int floorInBST(TreeNode<int> * node, int key)
{
    // Write your code here.
    int floor=-1;
    while(node){
        if(node->val==key) return node->val;
        else if(node->val<key){
            floor=node->val;
            node=node->right;
        }
        else node=node->left;
    }
    
    return floor;
}
