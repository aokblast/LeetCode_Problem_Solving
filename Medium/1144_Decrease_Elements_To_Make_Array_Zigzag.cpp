//dp
//Runtime 0
//Memory Usage 7.2

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size(), a = 0, b = 0;
        
        for(int i = 0; i < n; ++i) {
            int l = i == 0 ? INT_MAX : nums[i - 1];
            int r = i == n - 1 ? INT_MAX : nums[i + 1];
            if(i % 2)
                a += max(nums[i] - min(l, r) + 1, 0);
            else
                b += max(nums[i] - min(l, r) + 1, 0);
        }
        return min(a, b);
    }
};