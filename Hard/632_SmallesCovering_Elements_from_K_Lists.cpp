//Rolling Window
//Runtime 40
//Memory Usage 16.5
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> result(2);
        result[1] = INT_MAX;
        vector<pair<int, int>> ps;
        
        for(int i = 0; i < nums.size(); ++i){
            for(const auto num : nums[i]){
                ps.push_back({num, i});
            }
        }
        sort(ps.begin(), ps.end());
        
        int n = ps.size(), l = 0, r = 0, k = nums.size(), cur = 0;
        vector<int> cnt(k);
        while(r < n){
            while(r < n && cur < k){
                cur += (cnt[ps[r++].second]++) == 0;
            }
            while(l < r  && cur == k){
                cur -= (--cnt[ps[l++].second]) == 0;
            }
            int diff = result[1] - result[0];
            if(diff > ps[r - 1].first - ps[l - 1].first ) result[1] = ps[r - 1].first, result[0] = ps[l - 1].first;
        }
        
        return result;
    }
};