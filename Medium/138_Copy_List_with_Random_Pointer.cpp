//hash table
//Runtime 4 
//Memory Usage 11.3
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *trav = head;
        unordered_map<Node *, Node*> m;
        Node *dummy= new Node(-1);
        Node *f = dummy;
        while(trav != NULL){
            if(m.find(trav) != m.end()){
                f->next = m[trav];
            }else{
                f->next = new Node(trav->val);
                m[trav] = f->next;
            }
            f = f->next;
            if(f == NULL) break; 
            if(m.find(trav->random) != m.end()){
                f->random = m[trav->random];
            }else{
                f->random = trav->random == NULL ? NULL : new Node(trav->random->val);
                m[trav->random] = f->random;
            }
            trav = trav->next;
            
        }
        return dummy->next;
        
    }
};
