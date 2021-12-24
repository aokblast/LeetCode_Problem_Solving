//
//Runtime 48
//Memory Usage 32.4
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for(int i = 0; i < n - 1; ++i){
            if(nums[i] == nums[i + 1] - 1){
                int l = i, r = i + 1;
                while(l > 0 && nums[l - 1] == nums[l])--l;
                while(r < n - 1 && nums[r + 1] == nums[r]) ++ r;
                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};
