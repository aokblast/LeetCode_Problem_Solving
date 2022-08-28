//dfs
//Runtime 0
//Memory Usage 13.5

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        if(root->val < val)
            return new TreeNode(val, root, nullptr);
        return root->right = insertIntoMaxTree(root->right, val), root;
    }
};