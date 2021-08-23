//BFS
//Runtime 4
//Memory Usage 8.5

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node *result = new Node(node->val);
        queue<Node *> que;
        que.push(node);
        unordered_map<Node *, Node *> t;
        t[node] = result;
        Node *tmp;
        while(!empty(que)){
            tmp = que.front(); que.pop();
            for(Node *&n : tmp->neighbors){
                if(!t.count(n)){
                    t[n] = new Node(n->val);
                    que.push(n);
                }
                t[tmp]->neighbors.push_back(t[n]);
            }
        }
        return result;
        
    }
};
