//
//Runtime 0
//Memory Usage 12

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int exc = nums.size() - 2;
        while(exc >= 0 && nums[exc] >= nums[exc + 1]  )--exc;
        
        if(exc >= 0){
            int j = nums.size() - 1;
            while(nums[exc] >= nums[j]) --j;
            swap(nums[exc], nums[j]);
        }
        reverse(nums.begin() + exc + 1, nums.end());
    }
};
