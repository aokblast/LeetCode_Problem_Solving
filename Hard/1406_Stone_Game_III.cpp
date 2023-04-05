//
//Runtime 234
//Memory Usage 126.6

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int dp[n + 3];
        memset(dp, 0, sizeof dp);

        int sum = 0;

        for(int i = n - 1; i >= 0; --i) {
            sum += stoneValue[i];
            dp[i] = sum - min({dp[i + 1], dp[i + 2], dp[i + 3]});    
        }

        return dp[0] > (sum - dp[0]) ? "Alice" : (dp[0] < sum - dp[0]) ? "Bob" : "Tie"; 
    }
};