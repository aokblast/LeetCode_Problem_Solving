//
//Runtime 8
//Memory Usage 26.4
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
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int> &inorder, int pleft, int pright, int ileft, int iright){
        if(pleft > pright | ileft > iright) return NULL;
        TreeNode *root = new TreeNode(preorder[pleft]);
        int i = inorder[preorder[pleft]];
        root->left = buildTree(preorder, inorder, pleft + 1,  pleft + i - ileft, ileft,  i - 1);
        root->right = buildTree(preorder, inorder,  pleft + i - ileft + 1, pright, i  + 1, iright);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> ma;
        int size = preorder.size() - 1;
        for(int i = 0; i <= size; ++i) ma[inorder[i]] = i;
        return buildTree(preorder, ma, 0, size, 0, size);
    }
};
