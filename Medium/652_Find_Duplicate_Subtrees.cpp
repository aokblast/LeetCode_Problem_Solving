//
//Runtime 27
//Memory Usage 48.8

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
private:
    unordered_map<string, int> m;
    vector<TreeNode*> res;
    string dfs(TreeNode *root){
        if(!root)return "#";
        string cur = to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);
        if((m[cur]++) == 1)res.push_back(root);
        return cur;
    }
};