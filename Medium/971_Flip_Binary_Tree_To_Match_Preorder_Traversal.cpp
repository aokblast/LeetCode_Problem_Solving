//DFS
//Runtime 0
//Memory Usage 14.3

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
    vector<int> res;
    int cur = 0;
    bool dfs(TreeNode *root, vector<int> &voyage){
        if(!root)
            return true;
        if(root->val != voyage[cur])
            return false;
        ++cur;
        if(dfs(root->left, voyage) && dfs(root->right, voyage))
            return true;
        
        res.push_back(voyage[cur - 1]);
        
        if(dfs(root->right, voyage) && dfs(root->left, voyage))
            return true;
        res.pop_back();
        --cur;
        
        return false;
        
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(dfs(root, voyage))
            return res;
        else
            return {-1};
    }
};