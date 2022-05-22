//dfs
//Runtime 566
//Memory Usage 163.9

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)
            return nullptr;
        if(original == target)
            return cloned;
        TreeNode *node = getTargetCopy(original->left, cloned->left, target);
        if(node)
            return node;
        node = getTargetCopy(original->right, cloned->right, target);
        if(node)
            return node;
        return nullptr;
    }
};
