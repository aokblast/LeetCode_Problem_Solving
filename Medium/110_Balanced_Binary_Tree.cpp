//
//Runtime 4
//Memory Usage 20.9
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
        int left = depCount(root->left);
        if(left == -1) return -1;
        int right = depCount(root->right);
        if(right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        else return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        
        if(depCount(root) != -1) return true;
        return false;
    }
};
