//
//Runtime 105
//Memory Usage 29

class Skiplist {
public:
    Skiplist() {
        head = new Node(-1, nullptr, nullptr);
    }
    
    bool search(int target) {
        Node *cur = head;
        
        while (cur) {
            while(cur->next && cur->next->val < target)
                cur = cur->next;
            
            if(cur->next && cur->next->val == target)
                return true;
            
            cur = cur->down;
        }
        
        return false;
    }
    
    void add(int num) {
        vector<Node*> st;
        Node *cur = head, *down;
        while (cur) {
            while (cur->next && cur->next->val < num) 
                cur = cur->next;
            st.push_back(cur);
            cur = cur->down;
        }
        bool insert = true;
        while (insert && !st.empty()) {
            cur = st.back(); st.pop_back();
            cur->next = new Node(num, cur->next, down);
            down = cur->next;
            insert = (rand() & 1) == 0;
        }
        if (insert) 
            head = new Node(-1, nullptr, head);
    }
    
    bool erase(int num) {
        Node *cur = head;
        bool found = false;
        while (cur) {
            while (cur->next && cur->next->val < num) 
                cur = cur->next;
            if (cur->next && cur->next->val == num) {
                found =  true;
                cur->next = cur->next->next;
            }
            cur = cur->down;
        }
        return found;
    }
    
private:
    
    struct Node {
        int val;
        Node *next, *down;
        Node(int val, Node *next, Node *down) : val(val), next(next), down(down) {}
    };
    
    Node *head;
    
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */