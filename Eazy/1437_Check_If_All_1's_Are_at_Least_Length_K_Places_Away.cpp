//
//Runtime 55
//Memory Usage 57.6

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), t = find(nums.begin(), nums.end(), 1) - nums.begin();

        for(int i = t + 1; i < n; ++i) {
            if(nums[i] == 1) {
                if((i - t - 1) < k)
                    return false;
                t = i;
            }
        }

        return true;
    }
};