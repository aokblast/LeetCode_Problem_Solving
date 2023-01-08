//dp
//Runtime 136
//Memory Usage  82.8
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i  = 0; i < len; ++i){
            int num = nums[i];
            while(num > 0 && num <= len && nums[num - 1] != num) { swap(nums[num - 1], nums[i]);num = nums[i];}
        }
        for(int i = 0; i < len; ++i) if(nums[i] != i + 1) return i + 1;
        return len + 1;
    }
};
