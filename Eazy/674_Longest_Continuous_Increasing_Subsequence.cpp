//Scrolling Windows
//Runtime 4
//Memory Usage 11.1
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), res = 0;
        while(r < n){
            while(r < n - 1 && nums[r] < nums[r + 1])
                ++r;
            res = max(res, r - l + 1);
            l = ++r;
        }
        return res;
    }
};