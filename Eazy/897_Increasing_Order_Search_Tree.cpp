//dfs
//Runtime 0
//Memory Usage 7.7

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
    using Tp = TreeNode *;
    Tp dfs(Tp root, Tp next = nullptr){
        if(!root)
            return next;
        root->right = dfs(root->right, next);
        Tp tmp = dfs(root->left, root);
        root->left = nullptr;
        return tmp;  
    } 
    
    TreeNode* increasingBST(TreeNode* root) {
        return dfs(root);
    }
};