//hash_map + linked_list
//Runtime 356
//Memory Usage 170
static const int _=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}();
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto iter = m.find(key);
        if(iter == m.end()) return -1;
        l.splice(l.begin(), l, iter->second);
        return iter->second->second;
    }
     
    void put(int key, int value) {
        auto iter = m.find(key);
        if(iter != m.end())l.erase(iter->second);

        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if(m.size() > cap){
                m.erase(l.rbegin()->first);
                l.pop_back();
        }

    }
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
