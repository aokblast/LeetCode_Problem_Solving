//dp
//Runtime 4
//Memory Usage 8

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int lim = sum / 2;
        bool dp[lim + 1];
        
        memset(dp, 0, sizeof(dp));
        
        dp[0] = true;
        
        for(const int stone : stones) 
            for(int i = lim; i >= stone; --i)
                dp[i] |= dp[i - stone];
        
        for(int i = lim; i >= 0; --i)
            if(dp[i])
                return sum - i * 2;
        
        return 0;
        
        
        
    }
};