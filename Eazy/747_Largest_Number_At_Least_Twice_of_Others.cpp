//Runtime 3
//Memory Usage 10.9
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int midx = 0, n = nums.size(), mx = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] > mx)
                midx = i, mx = nums[i];
        }
        for(int i = 0; i < n; ++i)
            if(nums[i] * 2 > mx && i != midx)
                return -1;
        
        return midx;
        
    }
};