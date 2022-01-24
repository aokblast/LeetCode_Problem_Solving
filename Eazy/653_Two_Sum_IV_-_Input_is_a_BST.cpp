//Runtime 53
//Memory Usage 36.3
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
    int v[10005] = {0};
    int n = 0;
    void dfs(TreeNode *root){
        if(!root)return;
        dfs(root->left);
        v[n++] = root->val;
        dfs(root->right);
        return ;
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int l = 0, r = n - 1;
        while(l < r){
            int val = v[l] + v[r];
            if(val < k)++l;
            else if(val > k) --r;
            else return true;
        }
        return false;
    }
};