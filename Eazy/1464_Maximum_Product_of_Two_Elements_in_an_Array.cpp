//
//Runtime 3
//Memory Usage 10.1

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return ((nums.back() - 1) * ((*(++nums.rbegin())) - 1));
    }
};