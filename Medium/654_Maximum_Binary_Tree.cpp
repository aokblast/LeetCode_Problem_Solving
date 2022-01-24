//
//Runtime 60
//Memory Usage 39.3
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
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode *> v;
        for(const int num : nums){
            TreeNode *cur = new TreeNode(num);
            while(!v.empty() && v.back()->val < num){
                cur->left = v.back();
                v.pop_back();
            }
            if(!v.empty())
                v.back()->right = cur;
            v.push_back(cur);
        }
        return v.front();
    }
};