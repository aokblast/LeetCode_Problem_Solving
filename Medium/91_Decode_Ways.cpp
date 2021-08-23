//dp
//Runtime 100
//Memory Usage 6.2

class Solution {
    int dp[105];
public:
    int numDecodings(string s) {
        dp[0] = 1;
        int len = s.length();
        for(int i = 1; i <= len; ++i){
            dp[i] = (s[i - 1] == '0' ? 0 : dp[i - 1]);
            if(i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) dp[i] += dp[i - 2];
        }
        return dp[len];
    }
};
