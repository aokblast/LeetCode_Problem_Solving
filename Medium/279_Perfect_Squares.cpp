//dp
//Runtime 52
//Memory Usage 5.9
class Solution {
public:
    int dp[10005];
    
    int numSquares(int n) {
        memset(dp, 0x7f, sizeof(dp));
        dp[0] = {0};
        for(int i  = 0; i <= n; ++i){
            int lim = sqrt(n - i);
            for(int j = 1; j <= lim; ++j){
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
        
    }
};

//four-squre theorem
class Solution {
public:
    int numSquares(int n) {
        while(!(n % 4)) n /= 4;
        if(n % 8 == 7) return 4;
        int sq = sqrt(n);
        for(int i = sq; i >= 1; --i){
            int b = sqrt(n - i * i);
            if(i * i + b * b == n){
                return !!i + !!b; 
            }
        }
        return 3;

    }
};

