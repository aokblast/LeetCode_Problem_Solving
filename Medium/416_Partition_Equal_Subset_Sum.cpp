//dp
//Runtime 80
//Memory 9.2

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int val = accumulate(nums.begin(), nums.end(), 0);
        if(val & 1) return false;
        int part = val >> 1;
        vector<bool> dp(part  + 1);
        dp[0] = true;
        for(auto &num : nums){
            for(int i = part; i >= num; --i){
                dp[i] = dp[i] || dp[i - num];
                if(dp[part] == true) break;
            }
            if(dp[part] == true) break;
        }
        return dp[part];
    }
};