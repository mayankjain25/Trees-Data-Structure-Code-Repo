/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Approach is to first keep a track of the parent of each node. Once that is done, keep a 'visited' map, and a queue. We will do a DFS from the target node. At depth=1, we will store all the nodes that have not currently been visited, and are at a depth 1 from the target node. The direction would be-> left node, right node, and the parent node. Once this is done, we go to the next depth - i.e the nodes that are at a depth 2 from the target node. How can we reach depth=2? Simple, the nodes that are at a depth 1 from those nodes that are at a depth 1 from the target node, in short, are the nodes that are at a depth 2 from the target node. We will push all such nodes in the queue and mark the visited array accordingly. We keep on checking whether the current  level is equal to 'k' or not, if currLevel=k, break. The nodes remaining in the queue would be the nodes that are at a depth K from the target node. We can push them accordingly in a vector.


class Solution {
private:
    void trackNodeParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*>&parentMap){
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            if(node->left){
                parentMap[node->left]=node;
                q.push(node->left);
            }
            if(node->right) {
                parentMap[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        trackNodeParents(root, parentMap);
        
        for(auto it:parentMap){
            cout<<it.first->val<<" "<<it.second->val<<endl;
        }
        
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        visited[target]=true;
        q.push(target);
        int currLevel=0;
        while(!q.empty()){
            if(currLevel++==k) break;
            int n=q.size();
            for(int i=1;i<=n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left and !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right and !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parentMap[node] and !visited[parentMap[node]]){
                    q.push(parentMap[node]);
                    visited[parentMap[node]]=true;
                }
            }
            
        }
        
        vector<int>result;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            result.push_back(node->val);
        }
        
        return result;
    }
};

