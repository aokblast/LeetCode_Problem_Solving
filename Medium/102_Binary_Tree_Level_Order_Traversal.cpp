//bfs
//Runtime 0
//Memory Usage 12.7
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
    vector<vector<int>> result;
    void bfs(TreeNode *root){
        vector<int> tmp;
        queue<TreeNode *> q;
        if(root)q.push(root);
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                TreeNode *n = q.front(); q.pop();
                tmp.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            result.push_back(tmp);
            tmp.clear();
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        return result;
    }
};
