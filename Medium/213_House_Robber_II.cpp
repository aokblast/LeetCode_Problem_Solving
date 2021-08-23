//dp
//Runtime 0
//Memory Usage 7.9
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
        
    }
    int rob(vector<int> &nums, int left ,int right){
        if(right - left <= 1) return nums[left];
        vector<int> dp(105, 0);
        
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left + 1], nums[left]);
            for(int i = left + 2; i < right; ++i){
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }

        return dp[right - 1];
    }
};
