//
//Runtime 123
//Memory Usage 56.7

class BrowserHistory {
    string st[105];
    int top = 0;
    int cur = 0;
public:
    BrowserHistory(string homepage) {
        st[cur] = homepage;
        cur = top = 1;
    }
    
    void visit(string url) {
        st[cur] = url;
        top = ++cur;
    }
    
    string back(int steps) {
        cur = max(cur - steps, 1);
        return st[cur - 1];
    }
    
    string forward(int steps) {
        cur = min(top, cur + steps);
        return st[cur - 1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */