//Rolling Window
//Runtime 4
//Memory Usage 10.6 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right = 0, left = 0;
        int size  = nums.size();
        int sum = 0;
        int result = INT_MAX;
        while(right < size){
            while(right < size && sum < target) sum += nums[right++];
            while( (sum) >= target) result = min(result, right - left),sum -= nums[left], ++left;
        }
        
        return result == INT_MAX ? 0 : result;
    }
};
