//bfs
//Runtime 116
//Memory Usage 61.8

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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *> q;
        int res = 0;
        if(root)
            q.push(root);
        while(!q.empty()){
            int sz = q.size();
            res = 0;
            while(sz--){
                TreeNode *top = q.front(); q.pop();
                res += top->val;
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
        }
        return res;
    }
};