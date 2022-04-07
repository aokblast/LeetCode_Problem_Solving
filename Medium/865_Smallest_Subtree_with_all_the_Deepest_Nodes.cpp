//dfs
//Runtime 4
//Memory Usage 14.3

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
    int he[505] = {0};
    int dfs(TreeNode *root){
        return !root ? 0 : (he[root->val] = max(dfs(root->left), dfs(root->right)) + 1);
    }
    TreeNode *dfs2(TreeNode *root){
        if(!root->left && !root->right)
            return root;
            
        if(!root->left)
            return dfs2(root->right);
        if(!root->right)
            return dfs2(root->left);
        int hl = he[root->left->val], hr = he[root->right->val];
        return hl == hr ? root : (hl < hr ? dfs2(root->right) : dfs2(root->left));
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root);
        return dfs2(root);
        
    }
};