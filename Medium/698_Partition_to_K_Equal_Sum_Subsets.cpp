//dfs + memo
//Runtime 62
//Memory Usage 26.3

class Solution {
public:
    int target, n, m, cnt = 0;
    vector<int> memo;
    bool dfs(int stat, int cur, vector<int> &nums){
        if(stat == ((1 << n) - 1))
           return cnt == m;
        if(memo[stat] == 0)
            return memo[stat];
        for(int i = 0; i < n; ++i){
            if(((stat >> i) & 1) || cur + nums[i] > target)
                continue;
            if(cur + nums[i] == target){
                ++cnt;
                if(dfs(stat | (1 << i), 0, nums))
                    return true;
                --cnt;
            }else
                if(dfs(stat | (1 << i), cur + nums[i], nums))
                    return true;
        }
        
        return memo[stat] = false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size(), m = k;
        memo = vector<int>(1 << n, -1);
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot % k)
            return false;
        target = tot / k;
        return dfs(0, 0, nums);
    }
};