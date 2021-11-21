//
//Runtime 12
//Memory Usage 18.8
class Solution {
public:
    unordered_set<int> s;
    int m, n;
    Solution(int _m, int _n) {
        m = _m, n = _n;
    }
    
    vector<int> flip() {
        while(true){
            int x = rand() % m, y = rand() % n;
            if(!s.count(x * n + y)){
                s.insert(x * n + y);
                return {x, y};
            }
        }
    }
    
    void reset() {
        s.clear();
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
