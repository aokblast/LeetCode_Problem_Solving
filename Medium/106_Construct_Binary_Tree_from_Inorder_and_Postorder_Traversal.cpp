//
//Runtime 8
//Memory Usage 26.5
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
    TreeNode* buildTree(unordered_map<int, int>& inorder, vector<int>& postorder, int ileft, int iright, int pright){
        if(ileft > iright ) return NULL;
        TreeNode *root = new TreeNode(postorder[pright]);
        int i = inorder[postorder[pright]];
        root->left = buildTree(inorder, postorder, ileft, i - 1,  pright - iright + i - 1);
        root->right = buildTree(inorder, postorder, i + 1, iright, pright - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> ma;
        int size = inorder.size();
        for(int i = 0; i < size; ++i){
            ma[inorder[i]] = i;
        }
        return buildTree(ma, postorder, 0, size - 1, size - 1);
    }
};
