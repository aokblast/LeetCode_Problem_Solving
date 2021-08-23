//Runtime 0
//Memory Usage 8.8
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto iter = remove(nums.begin(), nums.end(), val);
        return iter - nums.begin();
    }
};
