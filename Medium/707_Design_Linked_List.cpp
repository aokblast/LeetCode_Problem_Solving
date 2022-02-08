//
//Runtime 48
//Memory Usage 19.9

class MyLinkedList {
private:
    struct Node{
        int val = 0;
        Node *prev = NULL;
        Node *next = NULL;
    };
    Node *head;
    Node *tail;
    
public:
    MyLinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        auto *res = find(index);
        return (res == nullptr || res == tail) ? -1 : res->val;
    }
    
    void addAtHead(int val) {
        Node *nn = new Node();
        nn->val = val;
        nn->next = head->next;
        head->next->prev = nn;
        nn->prev = head;
        head->next = nn;
    }
    
    void addAtTail(int val) {
        Node *nn = new Node();
        nn->val = val;
        nn->prev = tail->prev;
        tail->prev->next = nn;
        nn->next = tail;
        tail->prev = nn;
    }
    
    void addAtIndex(int index, int val) {
        Node *res = find(index);
        if(!res)
            return;
        Node *nn = new Node();
        nn->val = val;
        nn->prev = res->prev;
        nn->prev->next = nn;
        res->prev = nn;
        nn->next = res;
    }
    void deleteAtIndex(int index) {
        Node *res = find(index);
        if(!res || res == tail)
            return;
        res->prev->next = res->next;
        res->next->prev = res->prev;
        delete res;
    }
private:
    Node *find(int index){
        Node *trav = head->next;
        while(index-- && trav)
            trav = trav->next;
        return trav;
    }
    

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */