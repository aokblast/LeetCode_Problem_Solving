//
//Runtime 32
//Memory Usage 8.6
class Solution {
public:
    int dp[1005] = {0}, p[1005] = {0};
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ma = 0, ind = 0;
        for(int i = n - 1; i >= 0; --i){
            for(int j = i + 1; j < n; ++j){
                if(!(nums[j] % nums[i]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                    if(dp[i] > ma){
                        ma = dp[i];
                        
                        ind = i;
                    }
                }
            }
        }
        vector<int> ans;
        ++ma;
        while(ma--){
            ans.push_back(nums[ind]);
            ind = p[ind];
        }
        return ans;
    }
};
