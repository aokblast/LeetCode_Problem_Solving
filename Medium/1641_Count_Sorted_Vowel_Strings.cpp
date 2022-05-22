//dp
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[50][5] = {0};
        for(int i = 0; i < 5; ++i)
            dp[0][i] = 1;
        for(int i = 1; i < n; ++i){
            int cur = 0;
            for(int j = 4; j >= 0; --j){
                cur += dp[i - 1][j];
                dp[i][j] = cur;
            }
        }
        int res = 0;
        for(int i = 0; i < 5; ++i){
            res += dp[n - 1][i];
        }
        return res;
    }
};