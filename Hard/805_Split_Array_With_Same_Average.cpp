//
//Runtime 154
//Memory Usage  9.1
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), m = n / 2, sum = accumulate(nums.begin(), nums.end(), 0);
        bool pos = false;
        for(int i = 1; i <= m; ++i)
            if((sum * i) % n == 0){
                pos = true;
                break;
            }
        if(!pos)
            return false;

        bitset<300001> s[m + 1];
        s[0] = 1;
        for(const int num : nums)
            for(int i = m; i >= 1; --i)
                s[i] |= s[i - 1] << num;
        for(int i = 1; i <= m; ++i){
            if((sum * i) % n == 0 && s[i][(sum * i) / n])
                return true;
        }
        return false;
    }
};