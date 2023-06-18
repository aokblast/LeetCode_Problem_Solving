//
//Runtime 92
//Memory Usage 35.3

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(begin(nums),end(nums));
        return size(nums)<=4 ?0 : min({nums[nums.size()-1]-nums[3]
        ,nums[nums.size()-2]-nums[2]
        ,nums[nums.size()-3]-nums[1]
        ,nums[nums.size()-4]-nums[0]});
    }
};