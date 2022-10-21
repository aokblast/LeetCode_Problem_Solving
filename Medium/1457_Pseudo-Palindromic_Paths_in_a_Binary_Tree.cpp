//
//Runtime 627
//Memory Usage 179.5
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
    int cnts[10] = {0};
    int res = 0;
    void dfs(TreeNode *r, int odds) {
        if(!r)
            return ;
        odds += (++cnts[r->val]) % 2;
        odds -= (cnts[r->val] % 2) == 0;
        if(!r->left && !r->right)
            return void((--cnts[r->val], res += odds <= 1));
        dfs(r->left, odds);
        dfs(r->right, odds);
        --cnts[r->val];
    };
    int pseudoPalindromicPaths (TreeNode* root) {

        
        dfs(root, 0);
        return res;
    }
};