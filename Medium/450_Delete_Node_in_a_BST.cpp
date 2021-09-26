//
//Runtime 24
//Memory Usage 32.8
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
    TreeNode* dfs(TreeNode *root, const int &key){
        if(!root)return NULL;
        if(key > root->val)root->right = dfs(root->right, key);
        else if(key < root->val)root->left = dfs(root->left, key);
        else {
            if(!root->left || !root->right){
                root = root->left ? root->left : root->right;
            }else{
                TreeNode *newroot = root->right;
                while(newroot->left)newroot = newroot->left;
                root->val = newroot->val;
                root->right = dfs(root->right, root->val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return dfs(root, key);
    }
};
