//
//Runtime: 164
//Memory Usage: 86.4

class FreqStack {
public:

    unordered_map<int, stack<int>> stks;
    int maxF = 0;
    unordered_map<int, int> frqs;
    FreqStack() {
        
    }
    
    void push(int val) {
        maxF = max(maxF, ++frqs[val]);
        stks[frqs[val]].push(val);
    
        
    }
    
    int pop() {
        int num = stks[maxF].top(); stks[maxF].pop();
        maxF -= stks[maxF].size() == 0;
        --frqs[num];
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */