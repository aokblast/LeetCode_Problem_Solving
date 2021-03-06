//
//Runtime 48
//Memory Usage 33.7
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int idx = abs(nums[i]) - 1;
            nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
