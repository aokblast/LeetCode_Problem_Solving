//kmp
//Runtime 41
//Memory Usage 15.1

class Solution {
public:
    string longestPrefix(string s) {
        int n= s.size(), dp[n];
        int i = 1, j = 0;

        memset(dp, 0, sizeof(dp));

        while(i < n) {
            if(s[i] == s[j])
                dp[i] = j + 1, ++i, ++j;
            else {
                if(j > 0)
                    j = dp[j - 1];
                else
                    dp[i] = 0, ++i;
            }
        }
        return s.substr(0, dp[n - 1]);
    }
};
