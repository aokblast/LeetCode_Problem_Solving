//
//Runtime 4
//Memory Usage 10
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> ans(2, 0);
        for(int &num : nums){
            if(num & diff) ans[0] ^= num;
            else ans[1] ^= num;
        }
        return ans;
    }
};
