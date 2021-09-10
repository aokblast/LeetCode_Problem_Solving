//DFS + Memorize
//Runtime 60
//Memory Usage 6 
class Solution {
public:
    int dp[205][205] = {{0}};
    int dfs(int l, int r){
        if(l >= r) return 0;
        if(dp[l][r])return dp[l][r];
        int ans = INT_MAX;
        for(int i = l; i <= r; ++i){
            ans = min(ans, i + max(dfs(l, i - 1), dfs(i + 1, r)) );
        }
        return dp[l][r] = ans;
    }
    int getMoneyAmount(int n) {
        return dfs(1, n);
    }
};
