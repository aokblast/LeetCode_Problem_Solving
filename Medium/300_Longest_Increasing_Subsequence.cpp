//Binary search
//Runtime 8
//Memory Usage 10.6
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tmp(nums.size(), INT_MAX);
        int ans = 0;
        for(int &num : nums){
            auto it = lower_bound(tmp.begin(), tmp.end(), num);
            ans = max((int)(it - tmp.begin() + 1), ans);
            *it = num;
        }
        return ans;
    }
};
