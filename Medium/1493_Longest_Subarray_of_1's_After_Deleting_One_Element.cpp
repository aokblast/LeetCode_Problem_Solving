//Sliding Window
//Runtime 39
//Memory Usage 36.4

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for(int l = 0, r = 0, cur = 0; r < n; ++r) {
            cur += nums[r];

            while(l < r && cur < (r - l))
                cur -= nums[l++];

            res = max(res, r - l);
        }

        return res;
    }
};