//dp
//Runtime 4 
//Memory Usage 6.9
class Solution {
public:
    int dp[5005] = {0};
    int change(int amount, vector<int>& coins) {
        dp[0] = 1;
        for(const int &c : coins){
            for(int cnt = c; cnt <= amount; ++cnt){
                dp[cnt] += dp[cnt - c];
            }
        }
        return dp[amount];
    }
};
