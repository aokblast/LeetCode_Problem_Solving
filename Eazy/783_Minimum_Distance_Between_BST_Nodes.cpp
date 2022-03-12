//Inorder Traversal
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
    int res = INT_MAX;
    int prev = -100000;
    void dfs(TreeNode *root){
        if(!root)
            return;
        dfs(root->left);
        res = min(res, root->val - prev);
        prev = root->val;
        dfs(root->right);

    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};