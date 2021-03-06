//
//Runtime 4
//Memory Usage 7.3
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head;
        while(cur){
            if(cur->child){
                Node *next = cur->next;
                cur->child = flatten(cur->child);
                Node *last = cur->child;
                while(last->next) last = last->next;
                cur->next = cur->child;
                cur->child = NULL;
                cur->next->prev = cur;
                last->next = next;
                if(next)next->prev = last;
            }
            cur = cur->next;
        }
        return head;
    }
};
