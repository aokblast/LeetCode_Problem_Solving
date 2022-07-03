//dp
//Runtime 21
//Memory Usage 10.1
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int dp[m];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < i; ++j){
                int k = 0;
                for(; k < n; ++k){
                    if(strs[k][j] > strs[k][i])
                        break;
                }
                if(k == n)
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        return m - *max_element(dp, dp + m) - 1;
        
        
    }
};