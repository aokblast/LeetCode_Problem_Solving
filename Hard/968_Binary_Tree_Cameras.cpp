//dfs
//Runtime 11
//Memory Usage  21.2
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
    int res = 0;
    enum Stat{
        NO,
        CAM,
        MON,
    };
    Stat dfs(TreeNode *root){
        if(!root)
            return MON;
        Stat left = dfs(root->left), right = dfs(root->right);
        if(left == NO || right == NO){
            ++res;
            return CAM;
        }
        return left == CAM || right == CAM ? MON : NO; 
    }
    int minCameraCover(TreeNode* root) {
        return (dfs(root) == NO) + res;
    }
};