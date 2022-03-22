//dp
//Runtime 12
//Memory Usage 5.9
class Solution {
public:
    int racecar(int target) {
        int dp[target + 1];
        dp[0] = 0;
        for(int i = 1; i <= target; ++i){
            dp[i] = INT_MAX;
            int cpos = 1, j = 1;
            for(; j < i; j = (1 << ++cpos) - 1){
                int cneg = 0;
                for(int k = 0; k < j; k = (1 << ++cneg) - 1){
                    dp[i] = min(dp[i], dp[i - (j - k)] + 2 + cpos + cneg);
                }
            }
            dp[i] = min(dp[i], cpos + ((i == j) ? 0 : dp[j - i] + 1));
                    
        }
        return dp[target];
    }
};