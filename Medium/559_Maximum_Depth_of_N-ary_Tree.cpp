//
//Runtime 12 
//Memory Usage 11 
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
    
    int maxDepth(Node* root) {
        queue<Node *> q;
        if(root)q.push(root);
        int ans = 0;
        while(!q.empty()){
            ++ans;
            int cnt = q.size();
            while(cnt--){
                Node *t = q.front(); q.pop();
                for(const auto c : t->children){
                    if(c)q.push(c);
                }
            }
        }
        return ans;
    }
};
