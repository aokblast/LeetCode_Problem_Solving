//dfs
//Runtime 35
//Memory Usgae 25,4

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
using Tp = TreeNode *;
class Solution {
public:
    vector<Tp> res;
    unordered_set<int> del;
    Tp dfs(Tp rt) {
        if(!rt)
            return nullptr;
            
        Tp l = dfs(rt->left), r = dfs(rt->right);
        rt->left = l, rt->right = r;
        if(del.count(rt->val)) {
            if(l != nullptr)
                res.push_back(l);
            if(r != nullptr)
                res.push_back(r);
            return nullptr;
        }else{
            return rt;
        }        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        
        for(const int num : to_delete)
            del.insert(num);
        
        root = dfs(root);
        if(root != nullptr)
            res.push_back(root);
        return res;
    }
};