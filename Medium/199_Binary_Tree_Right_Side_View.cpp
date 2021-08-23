//bfs
//Runtime 0
//Memory Usage 12.2
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
    vector<int> result;
    void bfs(TreeNode *root){
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode *top = q.front(); q.pop();
                if(size == 0) result.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        
    }
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return result;
    }
};
