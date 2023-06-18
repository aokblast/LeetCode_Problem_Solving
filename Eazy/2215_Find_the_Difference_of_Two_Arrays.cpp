//
//Runtime 36
//Memory Usage 26.3

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        bitset<2010> b1, b2;

        for(const auto num : nums1)
            b1[num + 1000] = true;

        for(const auto num : nums2)
            b2[num + 1000] = true;

        vector<vector<int>> res(2);

        for(int i = 0; i < 2010; ++i)
            if(b1[i] && !b2[i])
                res[0].push_back(i - 1000);
            else if(!b1[i] && b2[i])
                res[1].push_back(i - 1000);

        return res;
    }
};