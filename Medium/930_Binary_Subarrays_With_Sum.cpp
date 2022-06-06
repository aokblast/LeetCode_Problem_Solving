//prefix sum
//Runtime 49
//Memory Usage 29

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cur = 0, res = 0;
        int mp[nums.size() + 1];
        memset(mp, 0, sizeof(mp));
        mp[0] = 1;
        for(const int num : nums){
            cur += num;
            if(cur >= goal)
                res += mp[cur - goal];
            ++mp[cur];

        }
        return res;
    }
};