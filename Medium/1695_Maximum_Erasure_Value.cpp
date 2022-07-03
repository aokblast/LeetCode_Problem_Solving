//rolling windows
//Runtime 171
//Memory Usage 89.3

class Solution {
public:
    static const int MAXN = 1e5 + 5;
    bool has[MAXN] = {false};
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int res = 0, cur = 0;
        while(r < n){
            while(r < n && !has[nums[r]])
                cur += nums[r], has[nums[r++]] = true;
            res = max(res, cur);
            cur -= nums[l];
            has[nums[l++]] = false;
        }
        return res;
    }
};