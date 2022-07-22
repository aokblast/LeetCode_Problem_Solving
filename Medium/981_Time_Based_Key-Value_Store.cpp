//Binary Search
//Runtime 506
//Memory Usage 128.1

class TimeMap {
public:
    using pis = pair<int, string>;
private:
    
    unordered_map<string, vector<pis>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const auto &m = mp[key];
        auto iter = lower_bound(m.begin(), m.end(), make_pair(timestamp, string()), 
                           [](const auto &p1, const auto &p2){return p1.first < p2.first;});
        if(iter != m.end() && iter->first == timestamp)
            return iter->second;
        return iter == m.begin() ? "" : (--iter)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */