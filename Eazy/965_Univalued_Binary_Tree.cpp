//dfs
//Runtime 0
//Memory Usage 9.8

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
    int val;
    bool dfs(TreeNode *root){
        if(!root)
            return true;
        if(root->val != val)
            return false;
        return dfs(root->left) && dfs(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        return dfs(root);
    }
};