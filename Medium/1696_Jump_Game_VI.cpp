//Dp
//Runtime 252
//Memory Usage 90.6

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        
        int n = nums.size(), cur;
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            while(q.size() && q.top().second + k < i)
                q.pop();
            
            cur = (q.size() ? q.top().first : 0) + nums[i];
            
            q.push({cur, i});
        }
        
        return cur;
    }
};