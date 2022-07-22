//dfs
//Runtime 7
//Memory Usage 19.4

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
    string res = "~";
    void dfs(TreeNode *root, string &cur){
        if(!root)
            return;
        
        if(!root->left && !root->right){
            string tmp = cur + (char)(root->val + 'a');
            reverse(tmp.begin(), tmp.end());
            res = min(res, tmp);
            return;
        }
        cur += (char)(root->val + 'a');
        dfs(root->left, cur);
        dfs(root->right, cur);
        cur.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string cur;
        dfs(root, cur);
        return res;
    }
};