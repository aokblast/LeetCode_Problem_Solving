//bfs
//Runtime 21
//Memory Usage 22.4

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
class CBTInserter {
public:
    using Tp = TreeNode *;
    Tp r;
    vector<Tp> cur, next;
    CBTInserter(TreeNode* root) {
        int sz = 1;
        if(root)
            next.push_back(root);
        r = root;
        while(next.size() == sz){
            cur = next;
            next.clear();
            for(int i = 0; i < sz; ++i){
                Tp t = cur[i];
                if(t->left)
                    next.push_back(t->left);
                if(t->right)
                    next.push_back(t->right);
                
            }
            sz <<= 1;
        }
        next.clear();
        for(int i = 0; i < cur.size(); ++i){
            Tp t = cur[i];
            if(t->left)
                next.push_back(t->left);
            if(t->right)
                next.push_back(t->right);    
        }

        
    }
    
    int insert(int val) {
        if(next.size() == cur.size() * 2)
            cur = next, next.clear();
        int idx = next.size() / 2;
        int rem = next.size() % 2;
        Tp newNode = new TreeNode(val);
        next.push_back(newNode);
        if(rem)
            cur[idx]->right = newNode;
        else
            cur[idx]->left = newNode;
        return cur[idx]->val;
            
    }
    
    TreeNode* get_root() {
        return r;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */