//
//Runtime 20
//Memory Usage 22.3
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n + 1), res(2, 0);
        for(int i = 0; i < n; ++i)cnt[nums[i]]++;
        for(int i = 1; i <= n; ++i){if(!cnt[i])res[1] = i;if(cnt[i] == 2)res[0] = i;}
        return res;
    }
};