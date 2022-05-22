//
//Runtime  8
//Memory Usage 16.2

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, n = nums.size();
        for(int j = 0; j < n; ++j){
            if(nums[j] % 2 == 0){
                while(i < j && nums[i] % 2 == 0)
                    ++i;
                if(i < j){
                    swap(nums[i], nums[j]);
                }
            }
            
        }
        return nums;
    }
};