//
//Runtime 12 
//Memory Usage 24.6
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
    unordered_map<int, int> m;
    int ma  = 0;
    int dfs(TreeNode *root){
        if(!root)return 0;
        int sum = dfs(root->left) + dfs(root->right) + root->val;
        ++m[sum];
        ma = max(ma, m[sum]);
        return sum;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for(const auto &p : m){
            if(p.second == ma) ans.push_back(p.first);
        }
        return ans;
    }
};
