//
//Runtime 288
//Memory 71.3
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int mn = INT_MAX;
        for(int num : nums)
            num <<= (num & 1 ? 1 : 0), q.push(num), mn = min(mn, num);
        int res = q.top() - mn;
        while(q.top() % 2 == 0){
            int top = q.top(); q.pop();
            top >>= 1;
            q.push(top);
            mn = min(mn, top);
            res = min(res, q.top() - mn);
        }
        return res;
    }
};