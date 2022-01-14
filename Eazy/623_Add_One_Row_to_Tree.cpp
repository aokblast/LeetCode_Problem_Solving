//bfs
//Runtime 20 
//Memory Usage 25.2
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
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
                    return new TreeNode(val, root, NULL);
        }
        depth -= 2;
        queue<TreeNode *> q;
        q.push(root);
        while(depth-- > 0){
            int sz = q.size();
            while(sz--){
                TreeNode *tmp = q.front(); q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        int sz = q.size();
        while(sz--){
            TreeNode *tmp = q.front(); q.pop();
            tmp->left = new TreeNode(val, tmp->left, NULL);
            tmp->right = new TreeNode(val, NULL, tmp->right);
        }
        return root;
        
    }
};