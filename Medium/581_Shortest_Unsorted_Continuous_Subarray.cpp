//
//Runtime 16
//Memory Usage 27.3

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int ma = nums[0], start = 1, mi = nums[n - 1], end = 0;
        for(int i = 1; i < n; ++i){
            ma = max(ma, nums[i]);
            mi = min(mi, nums[n - i - 1]);
            if(ma > nums[i])end = i;
            if(mi < nums[n - i - 1])start = n - i - 1;
        }
        return end - start + 1;
        
    }
};