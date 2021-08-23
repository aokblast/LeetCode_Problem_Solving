//Morris Algorithm
//Runtime 20
//Memory Usage 24
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
class BSTIterator {
public:
    TreeNode *root;
    BSTIterator(TreeNode* _root) {
        root = _root;
    }
    
    int next() {
        if(root->left){
            TreeNode *trav = root->left;
            while(trav->right && trav->right != root){
                trav = trav->right;
            }
            if(trav->right == root) {
                trav->right = NULL;
                int val = root->val;
                root = root->right;
                return val;
            }else{
                trav->right = root;
                root = root->left;
                return next();
            }
            
        }else{
            int val = root->val;
            root = root->right;
            return val;
        }       
    }
    
    bool hasNext() {
        return root != NULL;
    }

    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
