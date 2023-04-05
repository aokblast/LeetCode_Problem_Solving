//dfs
//Runtime: 150
//Memory Usage: 101.3


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
private:
    struct E{
        int mi, ma, sum;
    };
public:
    int res = 0;

    E dfs(Tp u) {
        if(!u)
            return {INT_MAX, INT_MIN, 0};
        
        auto l = dfs(u->left), r = dfs(u->right);
        if(l.ma < u->val && r.mi > u->val) {
            res = max(res, l.sum + r.sum + u->val);
            return {min(l.mi, u->val), max(r.ma, u->val), l.sum + r.sum + u->val};
        }
        
        return {INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};