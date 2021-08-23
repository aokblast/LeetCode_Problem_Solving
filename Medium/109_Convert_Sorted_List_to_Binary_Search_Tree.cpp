//
//Runtime 20
//Memory Usage 31
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
    TreeNode *buildTree(ListNode *first, ListNode *last){
        if(first == last) return NULL;
        ListNode *fast = first;
        ListNode *slow = first;
        while(fast != last && fast->next != last){
                fast = fast->next->next;
                slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = buildTree(first, slow);
        root->right = buildTree(slow->next, last);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, NULL);
    }
};
