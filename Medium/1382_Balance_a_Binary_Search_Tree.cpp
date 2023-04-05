//
//Runtime 119
//Memory Usage 47

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<Tp> vals;

        function<void(Tp)> dfs1 = [&](Tp u) {
            if(!u)
                return;
            dfs1(u->left);
            vals.push_back(u);
            dfs1(u->right);
        };

        function<Tp(int, int)> dfs2 = [&](int l, int r) -> Tp {
            if(l > r)
                return nullptr;

            int mid = l + (r - l) / 2;

            Tp u = vals[mid];
            u->left = dfs2(l, mid - 1), u->right = dfs2(mid + 1, r);

            return u;
        };

        dfs1(root);
        return dfs2(0, vals.size() - 1);

    }
};