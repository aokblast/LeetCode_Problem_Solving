//
//Runtime 147
//Memory Usage  53.9
class Solution {
public:
    const static long MOD = 1e9 + 7;
    int sumSubseqWidths(vector<int>& nums) {
        long res = 0, rg = 1;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        
        for(int i = 0; i < n; ++i)
            res = (res + rg * (nums[i] - nums[n - i - 1])) % MOD, rg = (rg * 2) % MOD;
        
        
        return res % MOD;
        
        
    }
};