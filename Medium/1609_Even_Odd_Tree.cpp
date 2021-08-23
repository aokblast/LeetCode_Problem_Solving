//BFS
//Runtime 224
//Memory Usage 151

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
    queue<TreeNode*> q;
public:
    bool isEvenOddTree(TreeNode* root) {
        
        int size;
        q.push(root);
        int prev, present;
        TreeNode *presentNode;
        bool odd = true;
        while(!q.empty()){
            size = q.size();
            prev = odd ? INT_MIN : INT_MAX; 
            while(size--){
                presentNode = q.front(); q.pop();
                present = presentNode->val;
                if(odd &&  (!(present % 2) || prev >= present)){
                    return false;
                }else if(!odd && ((present % 2) || prev <= present)){
                    return false;
                }
                prev= present;
                if(presentNode->left) q.push(presentNode->left);
                if(presentNode->right) q.push(presentNode->right);
            }
            odd = !odd;
        }
        return true;
    }
};
