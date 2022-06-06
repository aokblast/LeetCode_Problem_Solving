// 
//Runtime 158
//Memory Usage 57.5

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push_back(t);
        while(t - q.front() > 3000)
            q.pop_front();
        return q.size();
    }
    deque<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */