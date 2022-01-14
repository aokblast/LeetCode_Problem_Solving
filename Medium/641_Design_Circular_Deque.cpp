//
//Runtime 20
//Memory Usage 16.9
class MyCircularDeque {
private:
    int n, front, end, cnt = 0;
    vector<int> v;
public:
    MyCircularDeque(int k) {
        v.resize(k);
        n = k;
        end = 0, front = n - 1;
    }
    
    bool insertFront(int value) {
        if(isFull())return false;
        ++cnt;
        v[front] = value;
        front = (front - 1 + n) % n;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        ++cnt;
        v[end] = value;
        end = (end + 1) % n;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        --cnt;
        front = (front + 1) % n;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        --cnt;
        end = (end - 1 + n) % n;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : v[(front + 1) % n];
    }
    
    int getRear() {
        return isEmpty() ? -1 : v[(end - 1 + n) % n];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */