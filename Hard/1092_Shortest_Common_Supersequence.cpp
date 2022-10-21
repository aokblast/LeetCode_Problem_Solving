//LCS
//Runtime 15
//Memory Usage 10.6
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int dp[n + 1][m + 1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        
        
        int i = n, j = m;
        string res;
        while(i && j) {
            if(str1[i - 1] == str2[j - 1])
                res.push_back(str1[i - 1]), --i, --j;
            else {
                if(dp[i][j - 1] > dp[i - 1][j])
                    res.push_back(str2[j - 1]), --j;
                else
                    res.push_back(str1[i - 1]), --i;
            }
        }
        
        while(i)
            res.push_back(str1[i - 1]), --i;
        while(j)
            res.push_back(str2[j - 1]), --j;
        reverse(res.begin(), res.end());
        return res;
    }
};