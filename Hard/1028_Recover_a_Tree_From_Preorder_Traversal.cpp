//dfs
//Runtime 26
//Memory 19.4
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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        TreeNode *stk[1005];
        int top = 0;
        int i = 0;
        int val = 0;
        while(isdigit(traversal[i]))
            val = val * 10 + traversal[i] - '0', ++i;
        TreeNode *root = new TreeNode(val);
        stk[++top] = root;
        for(; i < n; ){
            int level = 0;
            while(traversal[i + level] == '-')
                ++level;
            i += level;
            int val = 0;
            while(isdigit(traversal[i]))
                val = val * 10 + traversal[i] - '0', ++i;
            
            if(top == level){
                stk[top]->left = new TreeNode(val);
                stk[++top] = stk[top]->left;
            }else{
                while(top > level)
                    --top;
                stk[top]->right = new TreeNode(val);
                stk[++top] = stk[top]->right;
            }
            
        }
        return root;
    }
};