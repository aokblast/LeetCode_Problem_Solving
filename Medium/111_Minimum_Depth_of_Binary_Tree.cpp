//
//Runtime 212
//Memory Usage 144.7
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
    int depCount(TreeNode *root){
        if(!root) return 0;
        if(!root->left) return 1 + depCount(root->right);
        if(!root->right) return 1 + depCount(root->left);
        return min(depCount(root->right), depCount(root->left)) + 1;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return depCount(root);
    }
};
