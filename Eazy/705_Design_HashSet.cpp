//
//Runtime 60
//Memory 74.5

class MyHashSet {
public:
    bool sets[1000005] = {false};
    MyHashSet() {
        
    }
    
    void add(int key) {
        sets[key] = true;
    }
    
    void remove(int key) {
        sets[key] = false;
    }
    
    bool contains(int key) {
        return sets[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */