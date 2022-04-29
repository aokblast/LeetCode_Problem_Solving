//
//Runtime 148
//Memory Usage 56.4

class UndergroundSystem {
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        int st = getID(stationName);
        trans[id] = {st, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int st = getID(stationName);
        auto [f, sTime] = trans[id];
        
        int key = (f << 12) | st;
        
        times[key].first += t - sTime;
        ++times[key].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        int f = getID(startStation), t = getID(endStation);
        
        int key = (f << 12) | t;
        
        auto [time , cnt] = times[key];
        
        return 1.0 * time / cnt;
    }
    
private:
    unordered_map<string, int> stID;
    unordered_map<int, pair<int, int>> trans;
    int tot = 0;
    unordered_map<int, pair<int, int>> times;
    int getID(const string &name){
        return stID.find(name) == stID.end() ? (stID[name] = tot++) : stID[name];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */