//dp
//Runtime 53
//Memory Usage 9.8
class Solution {
private:
    static const int MAX = 0x3f3f3f3f;
public:
    int minCost(vector<int>& houses, vector<vector<int>>& costs, int m, int n, int target) {
        int dp[n][target];
        memset(dp, 0x3f, sizeof(dp));
        
        
        if(houses[0])
            dp[houses[0] - 1][0] = 0;
        else
            for(int c = 0; c < n; ++c)
                dp[c][0] = costs[0][c];
        
        for(int h = 1; h < m; ++h){
            for(int s = min(h, target - 1); s; --s){
                for(int c1 = 0; c1 < n; ++c1){
                    if(houses[h] && houses[h] != c1 + 1){
                        dp[c1][s] = MAX;
                        continue;
                    }
                    int cost = MAX;
                    
                    for(int c2 = 0; c2 < n; ++c2)
                        cost = min(cost, c1 == c2 ? dp[c2][s] : dp[c2][s - 1]);
                    
                    dp[c1][s] = cost + (houses[h] ? 0 : costs[h][c1]);
                }
            }
            
            for(int c1 = 0; c1 < n; ++c1){
                if(houses[h] && houses[h] != c1 + 1){
                    dp[c1][0] = MAX;
                    continue;
                }
                
                dp[c1][0] = dp[c1][0] + (houses[h] ? 0 : costs[h][c1]);
            }
        }
        
        int res = MAX;
        
        for(int c = 0; c < n; ++c)
            res = min(res, dp[c][target - 1]);
        
        return res == MAX ? -1 : res;

    }
};