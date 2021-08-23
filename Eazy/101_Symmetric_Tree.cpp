//
//Runtime 4
//Memory Usage 16.5


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
    bool recur(TreeNode *left, TreeNode *right){
        return ((left == NULL || right == NULL) ? left == right : ((left->val == right->val)) && recur(left->left, right->right) &&  recur(left->right, right->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
           return root == NULL || recur(root->left, root->right);
    }
};
