//dp
//Runtime 2
//Memory Usage 7.8

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        int dp[n][n];
        if((n - 1) % (k - 1) != 0)
            return -1;
        memset(dp, 0, sizeof(dp));
        int prefix[n + 1];
        prefix[0] = 0;
        for(int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + stones[i];
        
        for(int len = k; len<= n; ++len){
            for(int l = 0; l + len <= n; ++l){
                int r = l + len - 1;
                dp[l][r] = INT_MAX;
                for(int mid = l; mid < r; mid += (k - 1)){
                    dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r]);
                }
                if((r - l) % (k - 1) == 0)
                    dp[l][r] += prefix[r + 1] - prefix[l];
            }
        }
        
        return dp[0][n - 1];
    
        
        
    }
};