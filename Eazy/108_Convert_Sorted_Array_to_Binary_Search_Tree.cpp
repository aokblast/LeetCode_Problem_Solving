//
//Runtime 12
//Memory Usage 21.4
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
    TreeNode* buildTree(vector<int> &nums, int left, int right){
        if(left > right) return NULL;
        int mid = (left + right) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, left , mid - 1);
        root->right = buildTree(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return buildTree(nums, 0, size - 1);
    }
};
