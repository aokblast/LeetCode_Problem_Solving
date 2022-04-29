//
//Runtime 218
//Memory Usage 96.6
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return true;
        int d = 0;
        
        
        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i - 1])
                continue;
            int cond = nums[i] > nums[i - 1] ? 1 : -1; 
            if(d == 0 || d == cond)
                d = cond;
            else
                return false;
        }
        return true;
    }
};