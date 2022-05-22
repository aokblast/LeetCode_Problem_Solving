//Greedy
//Runtime 24
//Memory Usage 15.4

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int res = nums[n - 1] - nums[0], l = nums[0] + k, r = nums[n - 1] - k;
        for(int i = 1; i < n; ++i){
            int mx = max(r, nums[i - 1] + k);
            int mn = min(l, nums[i] - k);
            res = min(res, mx - mn);
        }
        return res;
    }
};