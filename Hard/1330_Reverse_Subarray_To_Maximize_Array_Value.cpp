//Greedy
//Runtime 60
//Memory Usage 40.2

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size(), mx = INT_MIN, mn = INT_MAX, inc = 0, res = 0;
        
        for(int i = 1; i < n; ++i) {
            int a = nums[i - 1], b = nums[i];
            int cur = abs(b - a);
            res += cur;
            mx = max(mx, min(a, b));
            mn = min(mn, max(a, b));
            inc = max(inc, abs(b - nums.front()) - cur);
            inc = max(inc, abs(nums.back() - a) - cur);
        }

        return res + max(inc, 2 * (mx - mn));
    }
};