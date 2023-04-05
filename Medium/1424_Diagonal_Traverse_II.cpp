//
//Runtime 206
//Memory Usage 81.9

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int mx = 0, n = nums.size();

        for(const auto &num : nums)
            mx = max(mx, (int) num.size());

        vector<vector<int>> mp(n + mx);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < nums[i].size(); ++j)
                mp[i + j].push_back(nums[i][j]);
            
        vector<int> res;

        for(const auto &v : mp)
            res.insert(res.end(), v.rbegin(), v.rend());
        

        return res;
    }
};