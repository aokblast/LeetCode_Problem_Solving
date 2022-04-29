//prefix
//Runtime 0
//Memory Usage 12.6
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
    vector<int> v;
    int tot = 0;
    void dfs(TreeNode* root){
        if(!root)
            return;
        if(!root->left && !root->right)
            return void(v.push_back(root->val));
        dfs(root->left);
        dfs(root->right);
    }
    bool dfs2(TreeNode *root){
        if(!root)
            return true;
        if(!root->left && !root->right)
            return tot < v.size() && root->val == v[tot++];
        return dfs2(root->left) && dfs2(root->right);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        return dfs2(root2) && tot == v.size();
    }
};