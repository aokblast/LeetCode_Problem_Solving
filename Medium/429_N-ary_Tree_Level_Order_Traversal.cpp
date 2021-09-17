//
//Runtime 16
//Memory Usage 11.7
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<int> tmp;
        queue<Node *> q;
        if(root)q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node *f = q.front(); q.pop();
                tmp.push_back(f->val);
                for(Node *&n : f->children){
                    if(n)q.push(n);
                }
            }
            ans.push_back(tmp);
            tmp.clear();

        }
        return ans;
    }
};
