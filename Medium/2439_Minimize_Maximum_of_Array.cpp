//Greedy
//Runtime 116
//Memory Usage 71.3

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int res = nums[0], n = nums.size();
        long cur = nums[0];

        for(int i = 1; i < n; ++i)
            cur += nums[i], res = max(res, (int)((cur + i) / (i + 1)));
        
        return res;
    }
};