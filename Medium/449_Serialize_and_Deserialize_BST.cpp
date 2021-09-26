//
//Runtime 28
//Memory Usage 27.2
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
    void serialize(TreeNode *root, stringstream &ss){
        if(!root){
            ss << -1 << " ";
            return;
        }
        ss << root->val << " ";
        serialize(root->left, ss);
        serialize(root->right, ss);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }
    TreeNode* deserialize(stringstream &ss){
        
        int val;
        ss >> val;
        if(!~val){
            return NULL;
        }
        TreeNode *root = new TreeNode(val);
        root->left = deserialize(ss);
        root->right = deserialize(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
