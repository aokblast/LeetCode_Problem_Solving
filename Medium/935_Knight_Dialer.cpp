//
//Runtime 49
//Memory Usage 6.2

class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;
        int dp[10], next[10];
        vector<int> st[10] = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}}; 
        if(n == 1)
            return 10;
        for(int i = 0; i < 10; ++i)
            dp[i] = 1;
        
        for(int i = 2; i <= n; ++i){
            memset(next, 0, sizeof(next));
            for(int j = 0; j < 10; ++j)
                for(const int pre : st[j])
                    next[j] = (next[j] + dp[pre]) % MOD;
            memcpy(dp, next, sizeof(next));
            
        }
            
        
        int res = 0;
        for(int i = 0; i < 10; ++i)
            res = (res + next[i]) % MOD;
        return res;
    }
};