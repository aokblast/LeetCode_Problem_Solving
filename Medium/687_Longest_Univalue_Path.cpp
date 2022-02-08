//dfs
//Runtime 112
//Memory Usage 71.9

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
    int res = 0;
    int dfs(TreeNode *root){
        if(!root)
            return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if(root->left)
            l += root->left->val == root->val ? 1 : -l;
        if(root->right)
            r += root->right->val == root->val ? 1 : -r;
        res = max(res, l + r);
        return max(l, r);
            
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};