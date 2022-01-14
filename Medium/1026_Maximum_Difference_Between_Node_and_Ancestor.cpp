//dfs
//Runtime 0
//Memory 11.2
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
    vector<int> minStk;
    vector<int> maxStk;
    int res = 0;
    void dfs(TreeNode *root){
        if(!root)return;
        int val = root->val;
        res = max(abs(minStk.back() - val), max(abs(maxStk.back() - val), res));
        if(val < minStk.back())minStk.push_back(val);
        if(val > maxStk.back())maxStk.push_back(val);
        dfs(root->left);
        dfs(root->right);
        if(val == minStk.back())minStk.pop_back();
        if(val == maxStk.back())maxStk.pop_back();
        
    }
    int maxAncestorDiff(TreeNode* root) {
        minStk.push_back(root->val);
        maxStk.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        return res;
    }
};