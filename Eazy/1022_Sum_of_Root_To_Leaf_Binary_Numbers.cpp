//
//Runtime 4
//Memory Usage 16.7
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
    void dfs(TreeNode *root, int cur = 0){
        if(!root)return;
        cur = (cur << 1) | root->val;
        if(!root->left && !root->right){res += cur;return;}
        dfs(root->left, cur);
        dfs(root->right, cur);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return res;
    }
};