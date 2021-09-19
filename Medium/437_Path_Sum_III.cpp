//PrefixSum
//Runtime 12
//Memory Usage 18.8
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
    unordered_map<int ,int> psum;
    int ans = 0;
    void dfs(TreeNode *root, int &target, int preSum){
        if(!root)return ;
        preSum += root->val;
        if(preSum == target)++ans;
        if(psum.find(preSum - target) != psum.end() )ans += psum[preSum - target];
        ++psum[preSum];
        dfs(root->left, target, preSum);
        dfs(root->right, target, preSum);
        --psum[preSum];
    }
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0);
        return ans;
    }
};
