//dfs
//Runtime 0
//Memory Usage 13.7
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
    static TreeNode *dfs(const vector<int> &preorder, int idx, int r){
        int i = idx + 1;
        
        while(i <= r && preorder[i] < preorder[idx])
            ++i;
        
        TreeNode *cur = new TreeNode(preorder[idx]);

        if(i != idx + 1)
            cur->left = dfs(preorder, idx + 1, i - 1);
        if(i <= r)
            cur->right = dfs(preorder, i, r);
        
        return cur;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size() - 1);
    }
};