//dp
//Runtime 313
//Memory Usage 7.3
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size(), res = 0;
        
        int dp[1 << 16];
        
        memset(dp, -1, sizeof(dp));
        
        for(const int a : nums){
            for(const int b : nums){
                int x = a & b;
                
                if(dp[x] == -1){
                    dp[x] = 0;
                    for(const int c : nums)
                        dp[x] += (x & c) == 0;
                }
                res += dp[x];
            }
        }
    
        return res;
    }
};