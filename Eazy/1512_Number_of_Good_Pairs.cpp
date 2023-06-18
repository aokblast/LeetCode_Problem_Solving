//
//Runtime 0
//Memory Usage 7.2

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0, n = nums.size();

        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                res += nums[i] == nums[j];

        return res;
    }
};