//rolling window
//Runtime 175
//Memory Usage 98.6

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = INT_MAX, n = nums.size(), sum = 0, target = 0;
        int cur = 0, l = 0, r = 0;
        
        for(const int num : nums)
            sum += num;
        
        target = sum - x;
        
        while(r < n){
            cur += nums[r++];
            while(l < r && target < cur)
                cur -= nums[l++];
            if(target == cur)
                res = min(res, n - r + l);
        }
        return res == INT_MAX ? -1 : res;
    }
};