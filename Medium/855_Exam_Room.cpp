//set
//Runtime 32
//Memory Usage 15

class ExamRoom {
public:
    ExamRoom(int _n) {
        n = _n;
    }
    
    int seat() {
        if(s.size() == 0){
            s.insert(0);
            return 0;
        }
        if(s.size() == 1){
            int res = s.find(n - 1) == s.end() ? n - 1 : 0;
            s.insert(res);
            return res;
        }
        int mx = 0, res = 0;
        if(s.find(0) == s.end()){
            res = 0;
            mx = *s.begin();
        }
        auto it = s.begin(), last = s.begin();
        ++it;
        
        while(it != s.end()){
            int dis = *it - *last;
            if(dis / 2 > mx){
                res = dis / 2 + *last;
                mx = dis / 2;
            }
            ++it;
            ++last;
        }
        if(s.find(n - 1) == s.end() && n - 1 - *s.rbegin() > mx){
            res = n - 1;
        }
        s.insert(res);
        return res;
    }
    
    void leave(int p) {
        s.erase(p);
    }
    int n;
    set<int> s;

};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */