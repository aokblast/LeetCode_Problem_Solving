//Greedy
//Runtime 46
//Memory Usage 21.9
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int res = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = nums.size() - 1; i >= 2; --i)
            if(nums[i - 1] + nums[i - 2] > nums[i])
                return nums[i - 1] + nums[i - 2] + nums[i];
        
        return 0;
    }
};