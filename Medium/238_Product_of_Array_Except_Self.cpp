//
//Runtime 16 
//Memory Usage 24
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int res = 1, size = nums.size();
        vector<int> ans(size, 1);
        for(int i = 1; i < size; ++i){
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for(int i = size - 1; i >= 0; --i){
            ans[i] *= res;
            res *= nums[i];
        }
        return ans;
    }
};
