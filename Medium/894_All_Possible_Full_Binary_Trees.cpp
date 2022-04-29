//
//Runtime 106
//Memory Usage 28.1

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
    vector<TreeNode*> mp[21];
    vector<TreeNode*> allPossibleFBT(int n) {

        if(n == 1)
            return {new TreeNode(0)};
        else if(n == 0 || n % 2 == 0)
            return {};
        --n;
        if(mp[n].size())
            return mp[n];
        vector<TreeNode *> res;
        for(int i = 1; i < n; i += 2){
            
            auto l = allPossibleFBT(i);
            auto r = allPossibleFBT(n - i);
            
            for(TreeNode *ln : l){
                for(TreeNode *rn : r){
                    res.push_back(new TreeNode(0, ln, rn));
                }
            }
        }
            
        
        return mp[n] = res;
        

        
    }
};