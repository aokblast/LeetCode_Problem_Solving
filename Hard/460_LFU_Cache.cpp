//
//Runtime 452
//Memory Usage 186.8
class Solution {
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())return -1;
        freq[m[key].second].erase(iter[key]);
        freq[++m[key].second].push_back(key);
        iter[key] = --freq[m[key].second].end();
        if(freq[minf].empty()) ++minf;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(!cap)return;
        if(~get(key)){
            m[key].first = value;
            return;
        }
        
        if(m.size() >= cap){
            m.erase(freq[minf].front());
            iter.erase(freq[minf].front());
            freq[minf].pop_front();
        }
        m[key] = {value, 1};
        freq[1].push_back(key);
        iter[key] = --freq[1].end();
        minf = 1;
    }
    unordered_map<int, list<int>> freq;
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>::iterator> iter;
    int cap;
    int minf;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
