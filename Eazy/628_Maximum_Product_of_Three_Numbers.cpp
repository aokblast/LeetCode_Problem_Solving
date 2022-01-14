//
//Runtime 32
//Memory Usage 27.9
static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], max(nums[0] * nums[1] * nums[2], nums[0] * nums[1] * nums[n - 1]));
    }
};