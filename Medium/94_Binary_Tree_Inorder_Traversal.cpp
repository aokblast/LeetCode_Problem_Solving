//
//Runtime 0
//Memory Usage 8.3
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
    vector<int> result;
    void recur(TreeNode *root){
        if(root == NULL) return;
        recur(root->left);
        
        result.push_back(root->val);
        
        recur(root->right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        recur(root);
        return result;
    }
};
