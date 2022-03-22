//dfs
//Runtime 4
//Memory Usage 138.3

class Solution {
public:
    
    double dfs(vector<vector<double>> &memo, int a, int b){
        if(a <= 0 && b <= 0)
            return 0.5;
        if(a <= 0)
            return 1.0;
        if(b <= 0)
            return 0;
        if(memo[a][b] != -1)
            return memo[a][b];
        
        memo[a][b] = 0.25 * (dfs(memo, a - 100, b) + dfs(memo, a - 75, b - 25) + dfs(memo, a - 50, b - 50) + dfs(memo , a -25, b - 75));
    
        
        return memo[a][b];
    }
    
    double soupServings(int n) {
        if(n >= 4800)
            return 1;
        vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1));
        return dfs(memo, n, n);
        
    }
};
