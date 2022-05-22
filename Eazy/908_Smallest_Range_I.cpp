//
//Runtime 10
//Memory Usage 15.4
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mx = INT_MIN, mn = INT_MAX;
        
        for(const int num : nums)
            mx = max(mx, num), mn = min(mn, num);
    
        return mx - k <= mn + k ? 0 : mx - mn - 2 * k;
    }
};