//
//Runtime 32
//Memory Usage 31.4


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream s;
        serialize(root, s);
        return s.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return deserialize(s);        
        
    }
    void serialize(TreeNode *root, stringstream &is){
        if(!root){
            is << -1001 << ' ';
            return;
        }
        is << root->val << ' ';
        serialize(root->left, is);
        serialize(root->right, is);
    }
    TreeNode* deserialize(stringstream &is){
        int n;
        is >> n;
        if(n == -1001){
            return NULL;
        }else{
            TreeNode *root = new TreeNode(n);
            root->left = deserialize(is);
            root->right = deserialize(is);
            return root;
            
        }
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
