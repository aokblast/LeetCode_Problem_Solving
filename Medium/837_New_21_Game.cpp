//dp
//Runtime 3
//Memory Usage 6

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || k + maxPts <= n)
            return 1.0;
        double dp[10005] = {0.0};
        dp[0] = 1;
        
        double cur = 1.0, res = 0;
        for(int i = 1; i <= n; ++i){
            dp[i] = cur / maxPts;
            if(i < k)
                cur += dp[i];
            else
                res += dp[i];
            if(i >= maxPts)
                cur -= dp[i - maxPts];
        }
        return res;


    }
};