//
//Runtime 8 
//Memory Usage 10.8
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        for(const int &num : nums){
            ans += abs(num - mid);
        }
        return ans;
    }
};
