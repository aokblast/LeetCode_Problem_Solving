//
//Runtime 8
//Memory Usage 13.1
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int v = 0;
        for(const int num : nums)
            v ^= num;
        return v == 0 || nums.size() % 2 == 0;
    }
};