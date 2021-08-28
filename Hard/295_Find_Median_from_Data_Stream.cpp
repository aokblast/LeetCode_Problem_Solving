//priority_queue
//Runtime 248
//Memory Usage 117.1 
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> mi;
    priority_queue<int> ma;
    MedianFinder() {
        ios_base::sync_with_stdio(false);    
        cin.tie(NULL);
    }
    
    void addNum(int num) {
        mi.push(num);
        ma.push(-mi.top());
        mi.pop();
        if(mi.size() < ma.size()){
            mi.push(-ma.top());
            ma.pop();
        }
    }
    
    double findMedian() {
         return mi.size() > ma.size() ? mi.top() : 0.5 *(mi.top() - ma.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */ 
