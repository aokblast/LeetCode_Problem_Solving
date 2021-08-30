//dp
//Runtime 492
//Memory Usage 9
class Solution {
public:
    int dp[505][505]= {{0}};
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for(int len = 1; len <= n; ++len){
            for(int l = 1; l + len <= n + 1; ++l){
                int r =  l + len - 1;
                for(int p = l; p <= r; ++p){
                    dp[l][r] = max(dp[l][r], dp[l][p - 1] + dp[p + 1][r] + nums[l - 1] * nums[p] * nums[r + 1]);
                }

            }
        }
        return dp[1][n];
    }
};
