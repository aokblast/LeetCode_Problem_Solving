//
//Runtime 16
//Memory Usage 17.8

class MinStack {
public:
    /** initialize your data structure here. */
    int stack[30000];
    int minstk[30000];
    int ntop = 0;
    int minTop = 0;
    MinStack() {
        
    }
    
    void push(int val) {
        stack[ntop++] = val;
        if(minTop == 0 || minstk[minTop - 1] >= val) minstk[minTop++] = val;
    }
    
    void pop() {
        if(stack[ntop - 1] == minstk[minTop - 1]) --minTop;
        --ntop;
    }
    
    int top() {
        return stack[ntop - 1];
    }
    
    int getMin() {
        return minstk[minTop - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
