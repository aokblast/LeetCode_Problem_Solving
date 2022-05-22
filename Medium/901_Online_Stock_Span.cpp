//Monotonic Stack
//Runtime 243
//Memory Usage 84.3 
class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cur = 1;
        while(stk.size() && price >= stk.top().first)
            cur += stk.top().second, stk.pop();
        
        stk.push({price, cur});
        return cur;
        
    }
    stack<pair<int, int>> stk;

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */