//
//Runtime 12 
//Memory Usage 23.8
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
    int res=  0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }
private:
    int dfs(TreeNode *root){
        if(!root)return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        res += abs(l - r);
        return l + r + root->val;
    }    
};
