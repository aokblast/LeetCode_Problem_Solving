//BIT
//Runtime 224 
//Memory Usage 60.7
#define lowbit(x) (x & (-x))
class Solution {
public:
    int bit[50005] = {0};
    int reversePairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) m[v[i]] = i + 1;
        for (int i = n - 1; i >= 0; --i) {
            res += query(lower_bound(v.begin(), v.end(), nums[i] / 2.0) - v.begin());
            update(m[nums[i]], 1);
        }
        return res;
    }
    void update(int x, int num){
        for(; x < 5e4 + 5; x += lowbit(x)){
            bit[x] += num;
        }
    }
    
    int query(int x){
        int ans = 0;
        for(;x; x -= lowbit(x))ans += bit[x];
        return ans;
    }
};
