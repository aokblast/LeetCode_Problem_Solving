//dfs
//Runtime 8
//Memory Usage 19.8

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
   vector<vector<int>> ans;
  void dfs(TreeNode *node, int targetSum, vector<int> &presentVal){
    if(node == NULL) return;
    targetSum -= node->val;
    presentVal.push_back(node->val);
  	if(node->left == node->right) {
        if(targetSum == 0)ans.push_back(presentVal);
    }else{
        dfs(node->left, targetSum, presentVal);
 	    dfs(node->right,targetSum, presentVal);
    }

	presentVal.pop_back();
	targetSum += node->val;	
  }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       	vector<int> presentVal;
	 dfs(root, targetSum, presentVal);
	 return ans;   
    }
};
