//
//Runtime 112
//Memory Usage 51.9
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(m.find(key) == m.end()){
            if(l.empty() || l.back().val != 1){
                auto nb = l.insert(l.end(), {1, {key}});
                m[key] = nb;
            }else{
                auto last = --l.end();
                last->s.insert(key);
                m[key] = last;
            }
        }else{
            auto bucket = m[key], last = --m[key];
            if(last == l.end() || last->val != bucket->val + 1){
                auto nb = l.insert(bucket, {bucket->val + 1, {key}});
                m[key] = nb;
            }else{
                last->s.insert(key);
                m[key] = last;
            }
            bucket->s.erase(key);
            if(bucket->s.empty())l.erase(bucket);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m.find(key) == m.end())return;
        auto bucket = m[key];
        if(bucket->val == 1){
            bucket->s.erase(key);
            if(bucket->s.empty())l.erase(bucket);
            m.erase(key);
            return;
        }
        auto next = ++m[key];
        if(next == l.end() || next->val != bucket->val - 1 ){
            auto newb = l.insert(next, {bucket->val - 1, {key}});
            m[key] = newb;
        }else{
            next->s.insert(key);
            m[key] = next;
        }
        bucket->s.erase(key);
        if(bucket->s.empty()){
            l.erase(bucket);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return l.empty() ? "" : *(l.begin()->s.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return l.empty() ? "" : *(l.rbegin()->s.begin());
    }
    struct bucket{
        int val;
        unordered_set<string> s;
    };
    list<bucket> l;
    unordered_map<string, list<bucket>::iterator> m;
    
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
