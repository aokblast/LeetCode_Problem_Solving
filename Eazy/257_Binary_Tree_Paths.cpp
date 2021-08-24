//dfs
//Runtime 0
//Memory Usage 12.3
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
    vector<string> ans;
    
    void p(vector<int> &s){
        if(s.size() == 1){
            ans.push_back(to_string(s[0]));
        }else if(s.size() == 0){
            return;
        }else{
            string tmp;
            tmp += to_string(s[0]);
            for(int i = 1; i < s.size(); ++i){
                tmp += "->" + to_string(s[i]);
            }
            ans.push_back(tmp);
        
        }
    }
    
    void dfs(TreeNode *root, vector<int> &s){
        s.push_back(root->val);
        if(root->left && root->right){
            dfs(root->left, s);
            dfs(root->right, s);
        }else if(root->right){
            dfs(root->right, s);
        }else if(root->left){
            dfs(root->left, s);
        }else{
            p(s);
        }
        s.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> tmp;
        dfs(root, tmp);
        return ans;
    }
};
