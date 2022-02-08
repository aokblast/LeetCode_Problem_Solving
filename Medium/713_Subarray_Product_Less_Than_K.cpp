//
//Runtime 106
//Memory 61.3
class Solution {
public:

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, res = 0, n = nums.size();
        int cur = 1;
        for(int r = 0; r < n; ++r){
            cur *= nums[r];
            while(l <= r && cur >= k)
                cur /= nums[l++];
            res += r - l + 1;
        }
        return res;
        
    }
};