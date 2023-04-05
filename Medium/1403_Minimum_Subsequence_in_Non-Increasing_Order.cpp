//
//Runtime 4
//Memory Usage 10.7

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int sum = accumulate(nums.begin(), nums.end(), 0), acc = 0;

        vector<int> res;

        for(const int num : nums) {
            acc += num;
            res.push_back(num);

            if(acc > (sum - acc))
                return res;
        }


        return res;
    }
};