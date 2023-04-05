//dfs
//Runtime 33
//Memory Usage 32.5


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
using Lp = ListNode *;
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {

        function<bool(Lp, Tp)> dfs2 = [&](Lp list, Tp u) {
            if(!list)
                return true;
            if(u) {
                if(list->val != u->val)
                    return false;
                
                if(dfs2(list->next, u->left))
                    return true;
                
                if(dfs2(list->next, u->right))
                    return true;
                
                return false;
            } else
                return false;
        };

        function<bool(Tp)> dfs = [&](Tp u) {
            if(!u)
                return false;

            if(dfs2(head, u))
                return true;
            
            if(dfs(u->left))
                return true;

            if(dfs(u->right))
                return true;

            return false;
        };

        return dfs(root);
    }
};