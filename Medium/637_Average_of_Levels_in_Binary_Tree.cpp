//BFS
//Runtime 22
//Memory 22.4
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        double val = 0;
        int cnt = 0;
        queue<TreeNode *> q;
        if(root)q.push(root);
        while(!q.empty()){
            int sz = q.size();
            val = 0, cnt = sz;
            while(sz--){
                root = q.front();q.pop();
                val += root->val;
                if(root->left)q.push(root->left);
                if(root->right)q.push(root->right);
            }
            res.push_back(val / cnt);
        }
        return res;
    }
};