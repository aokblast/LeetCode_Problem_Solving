//bfs
//Runtime 3
//Memory Usage 10.5

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        if(root)
            q.push(root);
        bool left = false;
        while(!q.empty()){
            auto t = q.front(); q.pop();
            if(!t)
                left = true;
            else{
                if(left)
                    return false;
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
        
            
    }
};