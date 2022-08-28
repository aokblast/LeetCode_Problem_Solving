//
//Runtime 0 
//Memory Usage 9.1
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        for(; i < n && nums[i] < 0 && k; ++i, --k)
                nums[i] *= -1;
        
        if(k % 2){
            if(i > 0 && abs(nums[i]) > abs(nums[i - 1]))
                nums[i - 1] *= -1;
            else
                nums[i] *= -1;
        }
            
        
        return accumulate(nums.begin(), nums.end(), 0);
    }
};