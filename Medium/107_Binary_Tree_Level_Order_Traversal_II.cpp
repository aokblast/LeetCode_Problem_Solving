//bfs
//Runtime 4
//Memory Usage 12.6
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> tmp;
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(!q.empty()){
            int size = q.size();
            tmp.clear();
            while(size--){
                TreeNode *top = q.front(); q.pop();
                tmp.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            result.push_back(tmp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
