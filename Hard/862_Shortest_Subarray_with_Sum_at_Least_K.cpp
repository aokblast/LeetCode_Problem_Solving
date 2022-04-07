//greedy
//Runtime 261
//Memory Usage  110.3
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> ps(n + 1);
        for(int i = 0; i < n; ++i)
            ps[i + 1] = ps[i] + nums[i];
        int res = INT_MAX, tmp;
        deque<int> q;
        for(int i = 0; i <= n; ++i){
            while(!q.empty() && ps[i] <= ps[q.back()])
                q.pop_back();
            while(!q.empty() && ps[i] >= ps[q.front()] + k){
                int tmp = q.front(); q.pop_front();
                res = min(res, i - tmp);
            }
            q.push_back(i);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};