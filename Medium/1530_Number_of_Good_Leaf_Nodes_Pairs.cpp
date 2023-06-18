//dfs
//Runtime 39
//Memory Usage 27.6

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
    int countPairs(TreeNode* root, int distance) {
        int res = 0;

        function<array<int, 11>(TreeNode *)> dfs = [&](TreeNode *r) -> array<int, 11> {
            if(!r)
                return {0};

            array<int, 11> cur = {0};
            
            if(!r->left && !r->right) {
                cur[1]++;
                return cur;
            }

            auto left = dfs(r->left);
            auto right = dfs(r->right);

            for(int l = 1; l <= distance; ++l)
                for(int r = 1; r <= distance; ++r)
                    if(l + r <= distance)
                        res += left[l] * right[r];
            
            for(int i = distance; i >= 1; --i)
                cur[i] = left[i - 1] + right[i - 1];

            return cur;
        };

        dfs(root);
        return res;
    }
};