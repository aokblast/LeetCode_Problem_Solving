//
//Runtime 20
//Memory Usage 19.7
class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> q;
    int x;
    KthLargest(int k, vector<int>& nums) {
        x = k;
        for(const int num : nums){
            q.push(num);
            if(q.size() > k)
                q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > x)
            q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */