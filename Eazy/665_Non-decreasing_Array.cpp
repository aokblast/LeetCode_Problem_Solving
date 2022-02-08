//
//Runtime 28
//Memory Usage 27
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for(int i = 1; i <= n - 1; ++i){
            if(nums[i] < nums[i - 1]){
                if(cnt++ == 1)
                    return false;
                if(i == 1 || nums[i] >= nums[i - 2])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
            }
        }

        return true;
    }
};