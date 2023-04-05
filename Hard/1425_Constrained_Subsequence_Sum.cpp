//dp
//Runtime 285
//Memory Usage 115.2

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MIN;
        deque<int> q;
        int dp[n];

        for(int i = 0; i < n; ++i) {

            res = max(res, dp[i] = max(nums[i], nums[i] + (q.size() ? dp[q.front()] : 0)));
            int cur = dp[i];

            if(q.size() && (i - q.front()) == k)
                q.pop_front();
            
            while(q.size() && dp[q.back()] <= cur)
                q.pop_back();

            q.push_back(i);
        }

        return res;
    }
};