//
//Runtime 44
//Memory Usage 26.2
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right, cnt;
        int res = INT_MAX, mx = 0;
        for(int i = 0; i < nums.size(); ++i){
            const int num = nums[i];
            if(left[num] == 0)
                left[num] = i + 1;
            right[num] = i + 1;
            mx = max(++cnt[num], mx);
        }
        for(const auto [num, tot] : cnt)
            if(tot == mx)
                res = min(res, right[num] - left[num] + 1);
        return res;
    }
};