//dfs
//Runtime 183
//Memory Usage 113.8

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

 using Tp = TreeNode *;
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int res = 0;

        function<void(Tp, int l, int r)> dfs = [&](Tp u, int l, int r) {
            if(!u)
                return;

            res = max({res, l, r});
            dfs(u->left, 0, l + 1);
            dfs(u->right, r + 1, 0);
        };

        dfs(root, 0, 0);

        return res;
    }
};