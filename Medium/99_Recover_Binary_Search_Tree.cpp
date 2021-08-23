//morris
//Runtime 20
//Memory Usage 57.7
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
    void recoverTree(TreeNode* root) {
        TreeNode *cur = root, *first = NULL, *second = NULL, *pre = NULL;;
        while(cur){
            if(cur->left){    
                TreeNode *prev = cur->left;
                while(prev->right != cur && prev->right) prev = prev->right;
                if(!prev->right){
                    prev->right = cur;
                    cur = cur->left;
                    continue;
                }else{
                    prev->right = NULL;
                }
            }
            if(pre && pre->val > cur->val){
                if(!first) first = pre;
                second = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};
