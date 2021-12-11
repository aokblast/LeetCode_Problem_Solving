//
//Runtime 20 
//Memory Usage 15.3 
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* t1, Node* t2) {
        if(t1->isLeaf)return t1->val ? t1 : t2;
        if(t2->isLeaf)return t2->val ? t2 : t1;
        Node *a = intersect(t1->topLeft, t2->topLeft);
        Node *b = intersect(t1->topRight, t2->topRight);
        Node *c = intersect(t1->bottomLeft, t2->bottomLeft);
        Node *d = intersect(t1->bottomRight, t2->bottomRight);
        if(a->val == b->val && b->val == c->val && c->val == d->val && a->isLeaf && b->isLeaf && c->isLeaf && d->isLeaf){
          return new Node(a->val, true);  
        }
        return new Node(false, false, a, b, c, d);
    }
};
