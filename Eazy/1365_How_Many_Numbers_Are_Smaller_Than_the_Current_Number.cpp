//
//Runtime 4
//Memory Usage 10.2

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        auto cur = nums;

        sort(cur.begin(), cur.end());

        vector<int> res;

        for(const auto num : nums) 
            res.push_back(lower_bound(cur.begin(), cur.end(), num) - cur.begin());

        return res;
    }
};