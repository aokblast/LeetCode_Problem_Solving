//dp
//Runtime 0
//Memory Usage 6.6 
class Solution {
public:
    unsigned int dp[1005] = {0}; 
    int combinationSum4(vector<int>& nums, int target) {
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= target; ++i){
            for(int &n : nums){
                if(i >= n) dp[i] += dp[i - n];
                else break;
            }
        }
        return dp[target];

    }
};
