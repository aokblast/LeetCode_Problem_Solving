//dp
//Runtime 12
//Memory Usage 6.1
class Solution {
public:
    bool dp[35][35][35];
    bool isScramble(string s1, string s2) {
        
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        int n = s1.size();
        for(int len = 1; len <= n; ++len){
            for(int i = 0; i <= n - len; ++i){
                for(int j = 0; j <= n - len; ++j){
                    if(len == 1) dp[i][j][len] = (s1[i] == s2[j]);
                    else{
                        for(int k = 1; k < len; ++k){
                            if((dp[i][j][k] && dp[i + k][j + k][len - k]) || 
                               (dp[i][j + len - k][k] && dp[i + k][j][len - k]))
                                dp[i][j][len] = true;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
