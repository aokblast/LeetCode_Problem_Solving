//inorder
//Runtime 8
//Memory Usage 21.9
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
    vector<int> val;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        inorder(root);
        int size = val.size();
        for(int i = 0; i < size - 1; ++i){
            if(val[i] >= val[i + 1]) return false;
        }
        return true;
    }
    void inorder(TreeNode *root){
        if(!root)return ;
        inorder(root->left);
        val.push_back(root->val);
        inorder(root->right);
    }

};
