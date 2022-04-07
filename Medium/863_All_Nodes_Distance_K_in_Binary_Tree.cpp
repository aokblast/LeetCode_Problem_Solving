//dfs + bfs
//Runtime 4
//Memory Usage 12.9

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
    
    int l = 0;
    vector<int> edges[505];
    bool visit[505] = {false};
    void dfs1(TreeNode *root){
        if(!root)
            return;
        if(root->left){
            edges[root->val].push_back(root->left->val);
            edges[root->left->val].push_back(root->val);
            dfs1(root->left);
        }
        if(root->right){
            edges[root->val].push_back(root->right->val);
            edges[root->right->val].push_back(root->val);
            dfs1(root->right);
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs1(root);
        queue<int> q;
        q.push(target->val);
        visit[target->val] = true;
        while(!q.empty() && k--){
            int sz = q.size();
            while(sz--){
                int front = q.front(); q.pop();
                for(const auto adj : edges[front]){
                    if(!visit[adj]){
                        visit[adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
        vector<int> res;
        while(!q.empty())
            res.push_back(q.front()), q.pop();
        return res;
    }
};