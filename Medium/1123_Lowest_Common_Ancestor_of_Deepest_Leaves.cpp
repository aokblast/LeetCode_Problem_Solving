//dfs
//Runtime 22
//Memory Usage 21.1

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
    int height[1005] = {0};
    
    int dfs(TreeNode *r) {
        return !r ? 0 : (height[r->val] = max(dfs(r->left), dfs(r->right)) + 1);
    }
    
    TreeNode *dfs2(TreeNode *r) {
        if(!r->left && !r->right)
            return r;
        if(!r->left)
            return dfs2(r->right);
        if(!r->right)
            return dfs2(r->left);
        
        int hl = height[r->left-> val], hr = height[r->right->val];
        
        return hl == hr ? r : (hl < hr ? dfs2(r->right) : dfs2(r->left));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root);
        return dfs2(root);
    }
};