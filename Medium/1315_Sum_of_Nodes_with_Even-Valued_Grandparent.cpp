//dfs
//Runtime 43
//Memory Usage 41.3

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
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;

        function<void(TreeNode *, int)> dfs = [&](TreeNode *u, int pv) {
            if(!u)
                return;
            bool ev = !(pv % 2);
            
            if(u->left) {
                if(ev)
                    res += u->left->val;
                dfs(u->left, u->val);
            }
            if(u->right) {
                if(ev)
                    res += u->right->val;
                dfs(u->right, u->val);
            }
        };

        dfs(root, -1);
        
        return res;
    }
};