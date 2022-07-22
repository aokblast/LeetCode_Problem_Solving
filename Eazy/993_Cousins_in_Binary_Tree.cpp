//
//Runtime 0
//Memory Usage 11
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
    bool isCousins(TreeNode* root, int x, int y) {
        auto [dx, px] = dfs(root, x, 0, 0);
        auto [dy, py] = dfs(root, y, 0, 0);
        return dx == dy && px != py;
    }
private:
    pair<int, int> dfs(TreeNode *root, int val, int p, int d){
        if(!root)
            return {0, 0};
        if(root->val == val)
            return {d, p};
        auto l = dfs(root->left, val, root->val, d + 1);
        auto r = dfs(root->right, val, root->val, d + 1);
        return l.second ? l : r;
    }    
};