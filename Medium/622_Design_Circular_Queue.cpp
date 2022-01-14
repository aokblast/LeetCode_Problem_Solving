//
//Runtime 24
//Memory Usage 16.9
class MyCircularQueue {
public:
    

    MyCircularQueue(int k) {
        v.resize(k);
        n = k;
    }
    
    bool enQueue(int val) {
        if(isFull()) return false;
        ++front;
        v[front % n] = val;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        ++end;
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        int tmp = end + 1;
        return v[tmp % n];
        
    }
    
    int Rear() {
        if(isEmpty())return -1;
        return v[front % n];
    }
    
    bool isEmpty() {
        return front == end;
    }
    
    bool isFull() {
        return end + n == front;
    }
    
private:
    int front = 0, end = 0, n;
    vector<int> v;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */