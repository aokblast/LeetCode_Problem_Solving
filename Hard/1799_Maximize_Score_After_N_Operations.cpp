//
//Runtime 130
//Memory 8
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size(), lim = 1 << n;

        unordered_map<int, int> gcds;
        int dp[lim];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                gcds[(1 << i) | (1<< j)] = __gcd(nums[i], nums[j]);
        
        for(int i = 0; i < lim; ++i) {
            int tot = __builtin_popcount(i);
            if(tot % 2)
                continue;
            for(const auto [k, v]: gcds) {
                if((i & k) != k)
                    continue;
                dp[i] = max(dp[i], dp[i ^ k] + tot / 2 * v);
            }
        }

        return dp[lim - 1];
    }
};