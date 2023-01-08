//Prefix Sum
//Runtime 127
//Memory Usage 79.2

class Solution {
public:
    long sum[100005] = {0};
    int minimumAverageDifference(vector<int>& nums) {
        // 5 / 1, (4 + 3 + 2 + 1) / 4 = 2.5, 2.5
        // (5 + 4) / 2, (3 + 2 + 1) / 3 = 2, 2.5
        int n = nums.size();
        long c = 0;
        
        for(int i = 0; i < n; ++i) 
            sum[i + 1] = c += nums[i];
        
        long tot = sum[n];
        
        int res = 0;
        long diff = LONG_MAX;
        
        for(int i = 1; i < n; ++i) {
            long l = (sum[i]) / i, r = (tot - sum[i]) / (n - i);
            long cur = abs(l - r);
            if(cur < diff)
                diff = cur, res = i - 1;
        }
        
        long cur = abs(tot / n);
        if(diff > cur)
            res = n - 1;
        
        
        return res;
    }
};