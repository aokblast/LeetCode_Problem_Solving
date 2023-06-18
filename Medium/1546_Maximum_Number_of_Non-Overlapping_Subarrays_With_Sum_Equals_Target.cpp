//Greedy
//Runtime 231
//Memory Usage 84.2

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int cur = 0, res = 0, n = nums.size(), right = -1;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for(int i = 0; i < n; ++i) {
            cur += nums[i];
            if(mp.count(cur - target)) {
                int left = mp[cur - target];
                if(left >= right)
                    res++, right = i;
            }

            mp[cur] = i;
        }

        return res;
    }
};