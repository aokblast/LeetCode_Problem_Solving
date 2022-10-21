//dfs
//Runtime 14
//Memory Usage 6.2

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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int a = 0, b = 0;
        function<int(TreeNode *)> dfs = [&](TreeNode *u) {
            if(!u) {
                return 0;            
            }
            int l = dfs(u->left), r = dfs(u->right);
            
            if(u->val == x)
                a = l, b = r;
                
            return l + r + 1;
        };
        dfs(root);
        int top = n - a - b - 1;
        
        vector<int> res = {a, b, top};
        sort(res.begin(), res.end());
        
        return res[2] > n - res[2];
    }
};