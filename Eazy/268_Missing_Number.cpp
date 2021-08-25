//
//Runtime 12
//Memory Usage 18
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n  = nums.size();
        int sum = (n + 1) * n / 2;
        for(auto &num : nums)sum -= num;
        return sum;
    }
};
