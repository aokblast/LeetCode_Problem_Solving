//DFS
//Runtime 15
//Memory Usage 21.8

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        function<TreeNode *(TreeNode *)> dfs = [&](TreeNode *u) -> TreeNode *{
            if(!u)
                return nullptr;
            u->left = dfs(u->left);
            u->right = dfs(u->right);

            if(!u->left && !u->right && u->val == target)
                return nullptr;
            
            return u;
        }

        return dfs(root);
    }
};