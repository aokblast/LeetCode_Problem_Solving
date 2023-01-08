//bfs
//Runtime 204
//Memory Usage 107.4

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
    
    int maxLevelSum(TreeNode* root) {
        using Tp = TreeNode*;
        queue<Tp> q;
        if(root)
            q.push(root);
        int val = INT_MIN, res = 0, cur = 1;
        while(q.size()) {
            int sz = q.size();
            int sum = 0;
            while(sz--) {
                Tp u = q.front(); q.pop();
                sum += u->val;
                if(u->left)
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
            }
            
            if(sum > val) {
                val = sum;
                res = cur;
            }
            
            ++cur;
        }
        return res;
    }
};