//Stack
//Runtime 23
//Memory Usage 21.2

class CustomStack {
    int ele[1005] = {0};
    int sz = 0, maxSz = 0;
public:
    CustomStack(int maxSize) : maxSz(maxSize) {

    }
    
    void push(int x) {
        if(sz < maxSz)
            ele[sz++] = x;
    }
    
    int pop() {
        if(sz > 0) {
            return ele[--sz];
        } else {
            return -1;
        }
    }
    
    void increment(int k, int val) {
        int lim = min(maxSz, k);
        for(int i = 0; i < lim; ++i)
            ele[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */