//BIT
//Runtime 315
//Memory Usage 70.1
class Solution {
public:
    int bit[40001] = {0};
    inline int query(int x){
        int ans = 0;
        for(;x;x -= (x & -x)) ans += bit[x];
        return ans;
    }
    inline void update(int x, int val){
        x += 1;
        for(;x < 40001; x += (x & -x)) bit[x] += val;
    }
    vector<int> countSmaller(vector<int>& nums) {
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i = n - 1; i >= 0; --i){
            ans[i] = query(nums[i] + 10000);
            update(nums[i] + 10000, 1);
        }
        return ans;
    }
};
