//
//Runtime 12
//Memory Usage 23.5
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
    void dfs(TreeNode *root, string &res){
        if(!root)return;
        res += to_string(root->val);
        if(root->left){
            res += "(";
            dfs(root->left, res);
            res += ")";
        }
        if(root->right){
            if(!root->left){
                res += "()";
            }
            res += "(";
            dfs(root->right, res);
            res += ")";
        }

        return ;
    }
    string tree2str(TreeNode* root) {
        string res;
        dfs(root, res);
        return res;
    }
};