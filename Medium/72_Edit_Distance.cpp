//dp
//Runtime 8
//Memory Usage 7.3

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length(), i, j;
        int dp[len1 + 1][len2 + 1];
        for(i = 0;  i <= len1; ++i) dp[i][0] = i;
        for(i = 0;  i <= len2; ++i ) dp[0][i] = i;
        for(i = 1; i <= len1; ++i){
            for(j = 1; j <= len2; ++j){
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
            
        }
        return dp[len1][len2];
    }
};
