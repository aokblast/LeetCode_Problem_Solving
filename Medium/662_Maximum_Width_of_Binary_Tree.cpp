//
//Runtime 8
//Memory Usage 17.4
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        if(root)q.push({root, 1});
        int res = 1;
        while(!q.empty()){
            int sz = q.size(), left = q.front().second, right = 0;
            while(sz--){
                auto p = q.front(); q.pop();
                right = p.second - left;
                if(p.first->left)q.push({p.first->left, right * 2 });
                if(p.first->right)q.push({p.first->right, right * 2 + 1});
            }
            res = max(res, right + 1);      
        }
        return res;
    }
};