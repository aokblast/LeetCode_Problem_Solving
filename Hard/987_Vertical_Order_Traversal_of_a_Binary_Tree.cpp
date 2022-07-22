//
//Runtime 3
//Memory 12.2
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
      
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, vector<int>>> mp;
        if(root)
            q.push({root, {0, 0}});
        while(!q.empty()){
            auto [u, p] = q.front(); q.pop();
            mp[p.first][p.second].push_back(u->val);
            if(u->left)
                q.push({u->left, {p.first - 1, p.second + 1}});
            if(u->right)
                q.push({u->right, {p.first + 1, p.second + 1}});
        }
        
        vector<vector<int>> res;
        
        for(auto &v : mp){
            vector<int> cur;
            for(auto &v2 : v.second){
                sort(v2.second.begin(), v2.second.end());
                for(const auto num : v2.second)
                    cur.push_back(num);
            }
            res.push_back(cur);
        }
        
        
        return res;
        
        
    }
};