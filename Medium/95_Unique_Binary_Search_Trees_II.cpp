//dfs + dp
//Runtime 12
//Memory Usage 12.4
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
    vector<TreeNode *>dp[10][10];
    vector<TreeNode*> dfs(int left, int right){
        if(left > right) return {NULL};
        if(!dp[left][right].empty()) return dp[left][right];
        vector<TreeNode*> result;
        for(int i = left; i <= right; ++i){
            auto a = dfs(left, i - 1), b = dfs(i + 1, right);
            for(auto &l : a){
                for(auto &r : b){
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return dp[left][right] = result;

    }
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};
