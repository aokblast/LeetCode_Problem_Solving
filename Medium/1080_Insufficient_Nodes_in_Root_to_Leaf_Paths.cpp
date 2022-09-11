//
//Runtime 56
//Memory Usage 33.5

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
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        function<TreeNode *(TreeNode *, int)> dfs = [&](TreeNode * root, int sum) -> TreeNode *{
            if(!root)
                return nullptr;
            if(!root->left && !root->right) 
                return root->val + sum >= limit ? root : nullptr;
            
            auto l = dfs(root->left, sum + root->val), r = dfs(root->right, sum + root->val);
            if(l == nullptr && r == nullptr)
                return nullptr;
            else
                root->left = l, root->right = r;
            return root;
        };
        return dfs(root, 0);
        
        
    }
};