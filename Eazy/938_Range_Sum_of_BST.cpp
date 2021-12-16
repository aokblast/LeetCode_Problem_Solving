//
//Runtime 84
//Memory Usage 64.7
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
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return !root ? 0 : (root->val >= low ? (root->val > high ? rangeSumBST(root->left, low, high) : root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high)) : rangeSumBST(root->right, low, high));
    }
};