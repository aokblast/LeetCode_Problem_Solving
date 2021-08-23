//dp
//Runtime 60
//Memory Usage 10.7

class Solution {
public:
    int dp[1005][1005] = {0};
    int lcs(string &s, string &sr){
        int length = s.length();
        for(int i = 1; i <= length; ++i){
            for(int j = 1; j <= length; ++j){
                if(s[i - 1] == sr[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[length][length];
    }
    
    
    
    int longestPalindromeSubseq(string s) {
        string sRev(s.rbegin(), s.rend());
        
        return lcs(s, sRev);
    }
};
