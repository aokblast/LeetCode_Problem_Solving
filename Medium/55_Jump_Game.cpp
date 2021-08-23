//Greedy
//Runtime 52
//Memory Usage 48.1

class Solution {
public:
    int canJump(vector<int>& nums) {
        int i = 0, length = nums.size(), far = 0;
        for(; i < length && i <= far; ++i) far = max(far, i + nums[i]);
        return (far >= length - 1);
        
    }
};
