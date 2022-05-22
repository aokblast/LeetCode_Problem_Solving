//greedy
//Runtime 69
//Memory Usage 39.9

class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), mx = nums[0], mn = nums[0], a = 0, b = 0, sum = 0;
        for(const int num : nums){
            a = max(a + num, num);
            b = min(b + num, num);
            mx = max(mx, a);
            mn = min(mn, b);
            sum += num;
        }
        if(mn == sum)
            return mx;
        return max(sum - mn, mx);
        
    }
};
