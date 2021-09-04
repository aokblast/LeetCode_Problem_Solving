//Memorized + DFS
//Runtime 12
//Memory Usage 25.5
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *        *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *         *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *          * };
 *           */
class Solution {
	public:
		    unordered_map<TreeNode *, int>m;

			    int rob(TreeNode* root) {
					        return m[root] ? m[root] : m[root] = (!root ? 0 : max(rob(root->left) + rob(root->right), 
										                root->val + (root->left ? rob(root->left->left) + rob(root->left->right) : 0)+ (root->right ? rob(root->right->left)+ rob(root->right->right): 0) ));
							    }
};
				}
}
    }
//dfs
//Runtime 0
//Memory Usage 22.1
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *        *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *         *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *          * };
 *           */
class Solution {
	public:
		    pair<int,int> robSolve(TreeNode *root){
				        if(!root) return {0,0};
			        pair<int,int> left = robSolve(root->left);
			        pair<int,int> right = robSolve(root->right);
			        pair<int,int> res;
			        res.first = max(left.first,left.second) + max(right.first,right.second);
			        res.second = root->val + left.first + right.first;
			        return res;
			    }

    int rob(TreeNode* root) {
		        pair<int, int> ans = robSolve(root);
				        return max(ans.first, ans.second);
						    }
};
	}}
			}
}
 *   }
