//dp
//Runtime 25
//Memory Usage 6.1
class Solution {
public:
    int dp[100005] = {0};
    bool winnerSquareGame(int n) {
        dp[1] = true;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j * j <= i; ++j){
                if(!dp[i - j * j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};