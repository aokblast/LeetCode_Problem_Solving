//dfs
//Runtime 139
//Memory Usage 86.3

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
    
    void dfs(TreeNode *root, int cur) {
        if(!root)
            return ;
        if(cur <= root->val)
            ++res, cur = root->val;
        dfs(root->left, cur);
        dfs(root->right, cur);
        
    }
    int goodNodes(TreeNode* root) {
        dfs(root, -50000);
        return res;
    }
};