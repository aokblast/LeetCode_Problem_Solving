//
//Runtime 32
//Memory Usage 33.5
void dfs(TreeNode *root, int &val){
    if(!root)return;
    dfs(root->right, val);
    val += root->val;
    root->val = val;
    dfs(root->left, val);
    
}

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int v = 0;
        dfs(root, v);
        return root;
    }
};
