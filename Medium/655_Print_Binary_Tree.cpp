//dfs
//Runtime 0
//Memory Usage 8.4

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
    int h;
    int getH(TreeNode *root){
        return !root ? 0 : max(getH(root->left), getH(root->right)) + 1;
    }
    void dfs(vector<vector<string>> &res, TreeNode *root, int r, int c){
        res[r][c] = to_string(root->val);
        if(root->left)dfs(res, root->left, r + 1, c - (1 << (h - r - 2)));
        if(root->right)dfs(res, root->right, r + 1, c + (1 << (h - r - 2)));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        h = getH(root);
        int n = (1 << (h)) - 1;
        vector<vector<string>> res(h, vector<string>(n));
        queue<TreeNode *> q;
        if(root)q.push(root);

        if(root)dfs(res, root, 0, (n - 1) >> 1);
        return res;      
    }
};