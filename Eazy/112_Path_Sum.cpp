//
//Runtime 8
//Memory Usage 21.3
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
    bool dfs(TreeNode *root, int sum){
        if(!root) return false;
        sum += root->val;
        if(!root->left && !root->right){
            if(val == sum) return true;
            return false;
        }
        if(dfs(root->left, sum)) return true;
        if(dfs(root->right, sum)) return true;
        
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        val = targetSum;
        return dfs(root, 0);
    }
};
