//bucket_sort
//Runtime 133
//Memory Usage 78.3
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        auto mm = minmax_element(nums.begin(), nums.end());
        int range = *mm.second - *mm.first;
        int bucket_size =  range / n + 1;
        vector<int> min_val(n, INT_MAX);
        vector<int> max_val(n, INT_MIN);
        for(auto &num :nums){
            int idx = (num - *mm.first) / bucket_size;
            min_val[idx] = min(min_val[idx], num);
            max_val[idx] = max(max_val[idx], num);
        }
        int prev = max_val[0];
        int ans = 0;
        for(int i = 1; i< n; ++i){
            if(min_val[i] != INT_MAX){
                ans = max(ans, min_val[i] - prev);
                prev = max_val[i];
            }
        }
        return ans;
    }
};
