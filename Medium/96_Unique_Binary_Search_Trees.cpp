//dfs + dp
//Runtime 0
//Memory Usage 6
class Solution {
public:
    int dp[25][25];
    int dfs(int left, int right){
        if(left >= right) return 1;
        if(dp[left][right]) return dp[left][right];
        int ans = 0;        
        for(int i = left; i  <=  right; ++i){
            int l = dfs(left, i - 1), r = dfs(i + 1, right);
            ans += (l * r);
        }
        return dp[left][right] = ans;
    }
    int numTrees(int n) {
        return dfs(1, n);
    }
};
